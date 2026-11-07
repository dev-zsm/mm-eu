// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kakera.h"

void ref_func_8097E19C(EffectSs* this) {
    f32 range;
    f32 temp_f12;
    f32 temp_f16;
    f32 temp_f2;
    f32 temp_f18;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f2_2;

    temp_f18 = this->rReg5 / 1024.0f;
    temp_f20 = this->rReg6 / 1024.0f;
    range = (this->rReg9 / 1024.0f) * 4.0f;
    temp_f2 = this->velocity.x - ref_func_8097DE30(0.0f, range);
    temp_f16 = this->velocity.y - ref_func_8097DE30(0.0f, range);
    temp_f12 = this->velocity.z - ref_func_8097DE30(0.0f, range);
    temp_f0 = temp_f2 * temp_f18;
    temp_f2_2 = SQ(temp_f2) * temp_f20;
    if (temp_f2 > 0.0f) {
        this->velocity.x -= (temp_f0 + temp_f2_2);
    } else {
        this->velocity.x -= (temp_f0 - temp_f2_2);
    }
    temp_f0 = temp_f16 * temp_f18;
    temp_f2_2 = SQ(temp_f16) * temp_f20;
    if (temp_f16 > 0.0f) {
        this->velocity.y -= (temp_f0 + temp_f2_2);
    } else {
        this->velocity.y -= (temp_f0 - temp_f2_2);
    }
    if (temp_f12 > 0.0f) {
        this->velocity.z -= (temp_f0 + temp_f2_2);
    } else {
        this->velocity.z -= (temp_f0 - temp_f2_2);
    }
}
