// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bat.h"

void EnBat_StepAnimation(EnBat* this, s32 frameStep) {
    s32 prevFrame = this->animationFrame;

    this->animationFrame += frameStep;
    if (this->animationFrame >= ARRAY_COUNT(sWingsDLs)) {
        this->animationFrame -= ARRAY_COUNT(sWingsDLs);
    }
    if ((prevFrame < BAD_BAT_FLAP_FRAME) && (this->animationFrame >= BAD_BAT_FLAP_FRAME)) {
        Actor_PlaySfx(&this->actor, NA_SE_EN_FFLY_FLY);
    }
}
