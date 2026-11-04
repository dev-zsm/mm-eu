// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_olib.h"

Vec3s OLib_Vec3fDiffBinAng(Vec3f* a, Vec3f* b) {
    Vec3f anglesRad = OLib_Vec3fDiffRad(a, b);
    Vec3s anglesBinAng;

    anglesBinAng.x = CAM_DEG_TO_BINANG(RAD_TO_DEG(anglesRad.x));
    anglesBinAng.y = CAM_DEG_TO_BINANG(RAD_TO_DEG(anglesRad.y));
    anglesBinAng.z = 0.0f;

    return anglesBinAng;
}
