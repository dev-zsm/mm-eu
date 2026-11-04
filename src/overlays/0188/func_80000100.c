// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_swlift.h"

void BgF40Swlift_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    BgF40Swlift* this = (BgF40Swlift*)thisx;
    s32 i;

    for (i = 1; i < ARRAY_COUNT(sSwitchFlags); i++) {
        if ((sSwitchFlags[i] == 0xFF) || !Flags_GetSwitch(play, sSwitchFlags[i])) {
            break;
        }
    }

    i--;
    if (i != this->dyna.actor.params) {
        f32 heightOffset;

        this->dyna.actor.params = -1;
        heightOffset = (sHeights[i] - this->dyna.actor.world.pos.y) * 0.1f;
        if (heightOffset > 0.0f) {
            heightOffset = CLAMP(heightOffset, 0.5f, 15.0f);
        } else {
            heightOffset = CLAMP(heightOffset, -15.0f, -0.5f);
        }

        if (Math_StepToF(&this->dyna.actor.speed, heightOffset, 1.0f) && (fabsf(heightOffset) <= 0.5f)) {
            if (Math_StepToF(&this->dyna.actor.world.pos.y, sHeights[i], fabsf(this->dyna.actor.speed))) {
                this->dyna.actor.params = i;
                this->timer = 48;
                this->dyna.actor.speed = 0.0f;
            }
        } else {
            this->dyna.actor.world.pos.y += this->dyna.actor.speed;
        }
    } else {
        if (this->timer == 0) {
            this->timer = 48;
        }
        this->timer--;
        this->dyna.actor.world.pos.y =
            sHeights[this->dyna.actor.params] + (Math_SinF(this->timer * (M_PIf / 24)) * 5.0f);
    }
}
