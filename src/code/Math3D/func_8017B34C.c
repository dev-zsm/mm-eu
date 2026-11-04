// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_CirSquareVsTriSquareXY(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 centerX, f32 centerY, f32 radius) {
    f32 min;
    f32 max;

    if (v0->x < v1->x) {
        min = v0->x;
        max = v1->x;
    } else {
        min = v1->x;
        max = v0->x;
    }

    if (min > v2->x) {
        min = v2->x;
    } else if (max < v2->x) {
        max = v2->x;
    }

    if ((centerX < (min - radius)) || ((max + radius) < centerX)) {
        return false;
    }
    if (v0->y < v1->y) {
        min = v0->y;
        max = v1->y;
    } else {
        min = v1->y;
        max = v0->y;
    }
    if (min > v2->y) {
        min = v2->y;
    } else if (max < v2->y) {
        max = v2->y;
    }

    if ((centerY < (min - radius)) || (centerY > (max + radius))) {
        return false;
    }
    return true;
}
