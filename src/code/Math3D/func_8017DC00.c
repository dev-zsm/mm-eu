// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_TriChkPointParaZImpl(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 x, f32 y, f32 detMax, f32 chkDist, f32 nz) {
    f32 detv0v1;
    f32 detv1v2;
    f32 detv2v0;
    f32 distToEdgeSq;
    f32 chkDistSq;

    if (!Math3D_CirSquareVsTriSquareXY(v0, v1, v2, x, y, chkDist)) {
        return false;
    }

    chkDistSq = SQ(chkDist);

    if (((SQ(x - v0->x) + SQ(y - v0->y)) < chkDistSq) || ((SQ(x - v1->x) + SQ(y - v1->y)) < chkDistSq) ||
        ((SQ(x - v2->x) + SQ(y - v2->y)) < chkDistSq)) {
        
        return true;
    }

    if (((detMax >= (detv0v1 = ((v0->x - x) * (v1->y - y)) - ((v0->y - y) * (v1->x - x)))) &&
         (detMax >= (detv1v2 = ((v1->x - x) * (v2->y - y)) - ((v1->y - y) * (v2->x - x)))) &&
         (detMax >= (detv2v0 = ((v2->x - x) * (v0->y - y)) - ((v2->y - y) * (v0->x - x)))))) {
        return true;
    }

    if (((-detMax <= (detv0v1 = ((v0->x - x) * (v1->y - y)) - ((v0->y - y) * (v1->x - x)))) &&
         (-detMax <= (detv1v2 = ((v1->x - x) * (v2->y - y)) - ((v1->y - y) * (v2->x - x)))) &&
         (-detMax <= (detv2v0 = ((v2->x - x) * (v0->y - y)) - ((v2->y - y) * (v0->x - x)))))) {
        return true;
    }

    if (fabsf(nz) > 0.5f && chkDistSq > 0.0f) {

        if (Math3D_PointDistSqToLineXY(x, y, v0, v1, &distToEdgeSq) && (distToEdgeSq < chkDistSq)) {
            return true;
        }

        if (Math3D_PointDistSqToLineXY(x, y, v1, v2, &distToEdgeSq) && (distToEdgeSq < chkDistSq)) {
            return true;
        }

        if (Math3D_PointDistSqToLineXY(x, y, v2, v0, &distToEdgeSq) && (distToEdgeSq < chkDistSq)) {
            return true;
        }
    }

    return false;
}
