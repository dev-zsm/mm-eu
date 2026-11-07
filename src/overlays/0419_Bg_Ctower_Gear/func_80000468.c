// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ctower_gear.h"

void BgCtowerGear_Update(Actor* thisx, PlayState* play) {
    BgCtowerGear* this = (BgCtowerGear*)thisx;
    s32 type = BGCTOWERGEAR_GET_TYPE(&this->dyna.actor);

    if (type == BGCTOWERGEAR_CEILING_COG) {
        this->dyna.actor.shape.rot.x -= 0x1F4;
    } else if (type == BGCTOWERGEAR_CENTER_COG) {
        this->dyna.actor.shape.rot.y += 0x1F4;
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_WINDMILL_LEVEL - SFX_FLAG);
    } else if (type == BGCTOWERGEAR_WATER_WHEEL) {
        this->dyna.actor.shape.rot.z -= 0x1F4;
        BgCtowerGear_Splash(this, play);
    }
}
