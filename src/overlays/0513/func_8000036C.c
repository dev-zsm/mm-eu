// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_mirror.h"

void BgIkanaMirror_Wait(BgIkanaMirror* this, PlayState* play) {
    s8 isEmittingLight;
    s32 startEmittingLight = false;

    
    if (this->lightEmissionAlpha > 100) {
        this->lightEmissionAlpha -= 100;
    } else {
        this->lightEmissionAlpha = 0;
    }

    
    if (this->mirrorCollider.base.acFlags & AC_HIT) {
        this->mirrorCollider.base.acFlags &= ~AC_HIT;
        this->isEmittingLight = 0;

        if (this->lightRayCharge < 400) {
            this->lightRayCharge++;
        }

        if (this->lightAbsorptionAlpha < 195) {
            this->lightAbsorptionAlpha += 60;
        } else {
            this->lightAbsorptionAlpha = 255;
        }

    } else {
        isEmittingLight = this->isEmittingLight;

        if (isEmittingLight > 0) {
            startEmittingLight = true;
        } else if (this->lightRayCharge > 0) {
            this->isEmittingLight = isEmittingLight + 1;
        }
    }

    if (startEmittingLight) {
        BgIkanaMirror_SetupEmitLight(this);
    } else {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->mirrorCollider.base);
    }
}
