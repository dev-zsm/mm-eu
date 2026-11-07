// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_Moon_AdjustScaleAndPosition(EnFall* this, PlayState* play) {
    u16 currentTime = CURRENT_TIME;
    u16 dayStartTime = this->dayStartTime;
    f32 finalDayRelativeHeight;

    if (currentTime < dayStartTime) {
        finalDayRelativeHeight = 1.0f - (((f32)dayStartTime - (f32)currentTime) * (1.0f / 0x10000));
    } else {
        finalDayRelativeHeight = ((f32)currentTime - (f32)dayStartTime) * (1.0f / 0x10000);
    }
    switch (CURRENT_DAY) {
        case 0:
            Actor_SetScale(&this->actor, this->scale * 1.2f);
            this->actor.world.pos.y = this->actor.home.pos.y;
            break;

        case 1:
            Actor_SetScale(&this->actor, this->scale * 2.4f);
            this->actor.world.pos.y = this->actor.home.pos.y;
            break;

        case 2:
            Actor_SetScale(&this->actor, this->scale * 3.6f);
            this->actor.world.pos.y = this->actor.home.pos.y;
            break;

        case 3:
            Actor_SetScale(&this->actor, this->scale * 3.6f);
            if (EN_FALL_TYPE(&this->actor) == EN_FALL_TYPE_LODMOON_INVERTED_STONE_TOWER) {
                this->actor.world.pos.y =
                    this->actor.home.pos.y + (finalDayRelativeHeight * 6700.0f * (this->scale * 6.25f));
            } else {
                this->actor.world.pos.y =
                    this->actor.home.pos.y - (finalDayRelativeHeight * 6700.0f * (this->scale * 6.25f));
            }
            break;

        default:
            break;
    }
}
