// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_vspinyroll.h"

void ref_func_80A3C4E0(Vec3f* arg0, Vec3f* arg1, s16 arg2) {
    f32 sp1C = Math_SinS(arg2);
    f32 temp_f0 = Math_CosS(arg2);

    arg0->x = (arg1->z * sp1C) + (arg1->x * temp_f0);
    arg0->y = arg1->y;
    arg0->z = (arg1->z * temp_f0) - (arg1->x * sp1C);
}
