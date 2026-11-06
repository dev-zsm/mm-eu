// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kakera.h"

s32 ref_func_8097E584(EffectSs* this, Vec3f* diff, f32 distance) {
    static f32 (*ref_D_8097EB3C[])(f32, s32) = {
        ref_func_8097E368, ref_func_8097E384, ref_func_8097E384, ref_func_8097E384, ref_func_8097E3C0,
        ref_func_8097E3C0, ref_func_8097E3C0, ref_func_8097E400, ref_func_8097E400, ref_func_8097E400,
    };
    f32 center;
    f32 rand;
    s32 index;

    index = (this->rReg0 >> 7) & 0xF;
    center = ref_D_8097EB3C[index](distance, index);
    rand = ref_func_8097DE30(center, (this->rReg9 * center) / 1024.0f);
    this->accel.x *= rand;
    this->accel.y *= rand;
    this->accel.z *= rand;
    this->accel.x += rand * 0.01f;
    this->accel.y += rand * 0.01f;
    this->accel.z += rand * 0.01f;
    return true;
}
