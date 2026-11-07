// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_jgame_light.h"

void ObjJgameLight_UpdateFlame(ObjJgameLight* this, PlayState* play) {
    u8 brightness;

    if ((this->actor.colChkInfo.health & OBJJGAMELIGHT_IGNITE_FIRE) && !this->isOn) {
        if (this->lightRadius < 160) {
            this->lightRadius += 40;
        } else {
            this->lightRadius = 200;
            this->isOn = true;
        }
        if (this->flameScaleProportion < 0.7f) {
            this->flameScaleProportion += 0.3f;
        } else {
            this->flameScaleProportion = 1.0f;
        }
    } else if (this->actor.colChkInfo.health & OBJJGAMELIGHT_SNUFF_FIRE) {
        if (this->lightRadius > 40) {
            this->lightRadius -= 40;
        } else {
            this->lightRadius = -1;
            if (this->flameScaleProportion == 0.0f) {
                this->isOn = false;
                this->actor.colChkInfo.health &= ~OBJJGAMELIGHT_IGNITE_FIRE;
                this->actor.colChkInfo.health &= ~OBJJGAMELIGHT_SNUFF_FIRE;
            }
        }
        if (this->flameScaleProportion > 0.3f) {
            this->flameScaleProportion -= 0.3f;
        } else {
            this->flameScaleProportion = 0.0f;
        }
    }
    if (this->flameScaleProportion > 0.1f) {
        Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_TORCH - SFX_FLAG);
    }
    brightness = (s32)(Rand_ZeroOne() * 127.0f) + 128;
    Lights_PointSetColorAndRadius(&this->lightInfo, brightness, brightness * 0.7f, 0, this->lightRadius);
}
