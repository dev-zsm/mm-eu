// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

s32 ref_func_8093EAD4(Vec3f* arg0, Vec3f* arg1) {
    f32 temp_f0 = Math3D_Vec3fMagnitude(arg1);

    if (temp_f0 < 0.001f) {
        return false;
    }
    arg0->x = arg1->x * (1.0f / temp_f0);
    arg0->y = arg1->y * (1.0f / temp_f0);
    arg0->z = arg1->z * (1.0f / temp_f0);
    return true;
}
