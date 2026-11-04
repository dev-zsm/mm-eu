// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lib.h"

f32 Math_Vec3f_DistXYZ(Vec3f* a, Vec3f* b) {
    Vec3f diff;
    Math_Vec3f_Diff(b, a, &diff);
    return sqrtf(SQXYZ(diff));
}
