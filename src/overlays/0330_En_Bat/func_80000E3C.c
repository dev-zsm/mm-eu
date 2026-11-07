// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_Stunned(EnBat* this, PlayState* play) {
    Math_ScaledStepToS(&this->actor.shape.rot.x, 0, 0x100);
    if ((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) || (this->actor.floorHeight == BGCHECK_Y_MIN)) {
        if (this->timer != 0) {
            this->timer--;
        }
        if (this->timer == 0) {
            EnBat_SetupFlyIdle(this);
        }
    } else {
        this->actor.colorFilterTimer = 40;
        if (this->drawDmgEffAlpha > 0.0f) {
            this->drawDmgEffAlpha = 2.0f;
        }
    }
}
