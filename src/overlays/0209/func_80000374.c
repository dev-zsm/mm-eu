// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_hahen.h"

void EffectSsHahen_Draw(PlayState* play, u32 index, EffectSs* this) {
    f32 scale;

    if (this->rFlags & HAHEN_SMALL) {
        scale = this->rScale * (0.001f * 0.1f);
    } else {
        scale = this->rScale * 0.001f;
    }

    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_RotateYF(this->rYaw * 0.01f, MTXMODE_APPLY);
    Matrix_RotateXFApply(this->rPitch * 0.01f);
    Matrix_Scale(scale, scale, scale, MTXMODE_APPLY);

    if (this->rFlags & HAHEN_XLU) {
        EffectSsHahen_DrawXlu(play, this);
    } else {
        EffectSsHahen_DrawOpa(play, this);
    }
}
