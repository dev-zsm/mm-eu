// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_kakera.h"

s32 ref_func_8097E698(EffectSs* this) {
    Vec3f diff;
    f32 distance;

    ref_func_8097E34C(this);
    diff.x = this->pos.x - this->vec.x;
    diff.y = this->pos.y - this->vec.y;
    diff.z = this->pos.z - this->vec.z;
    distance = sqrtf(SQXYZ(diff));
    if (distance > 1000.0f) {
        return false;
    }
    if (this->rReg0 != 0) {
        if (!ref_func_8097E420(this, &diff, distance)) {
            return false;
        }
        if (!ref_func_8097E4B0(this, &diff, distance)) {
            return false;
        }
        if (!ref_func_8097E4F0(this, &diff, distance)) {
            return false;
        }
        if (!ref_func_8097E584(this, &diff, distance)) {
            return false;
        }
    }
    if (!ref_func_8097E660(this, &diff, distance)) {
        return false;
    } else {
        return true;
    }
}
