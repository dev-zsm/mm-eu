// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_olib.h"

Vec3f OLib_Vec3fDiffDegF(Vec3f* a, Vec3f* b) {
    Vec3f anglesRad = OLib_Vec3fDiffRad(a, b);
    Vec3f anglesDegrees;

    anglesDegrees.x = RAD_TO_DEG(anglesRad.x);
    anglesDegrees.y = RAD_TO_DEG(anglesRad.y);
    anglesDegrees.z = 0.0f;

    return anglesDegrees;
}
