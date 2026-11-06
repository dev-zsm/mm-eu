// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kakera.h"

s32 ref_func_8097E4F0(EffectSs* this, Vec3f* diff, f32 distance) {
    static f32 ref_D_8097EB30[] = { 0.1f, 1.0f, 6.0f };
    f32 phi_f0;
    s32 index = (this->rReg0 >> 5) & 3;

    if (index != 0) {
        if (distance > 1.0f) {
            phi_f0 = 1.0f / distance;
        } else {
            phi_f0 = 1.0f;
        }
        this->accel.x -= diff->x * ref_D_8097EB30[index - 1] * phi_f0;
        this->accel.z -= diff->z * ref_D_8097EB30[index - 1] * phi_f0;
    }
    return true;
}
