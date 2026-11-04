// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_TriChkPointParaYImpl(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 z, f32 x, f32 detMax, f32 chkDist, f32 ny) {
    f32 detv0v1;
    f32 detv1v2;
    f32 detv2v0;
    f32 distToEdgeSq;
    f32 chkDistSq;

    
    if (!Math3D_CirSquareVsTriSquareZX(v0, v1, v2, z, x, chkDist)) {
        return false;
    }

    
    chkDistSq = SQ(chkDist);
    if (((SQ(v0->z - z) + SQ(v0->x - x)) < chkDistSq) || ((SQ(v1->z - z) + SQ(v1->x - x)) < chkDistSq) ||
        ((SQ(v2->z - z) + SQ(v2->x - x)) < chkDistSq)) {
        return true;
    }

    
    
    if (((detMax >= (detv0v1 = ((v0->z - z) * (v1->x - x)) - ((v0->x - x) * (v1->z - z)))) &&
         (detMax >= (detv1v2 = ((v1->z - z) * (v2->x - x)) - ((v1->x - x) * (v2->z - z)))) &&
         (detMax >= (detv2v0 = ((v2->z - z) * (v0->x - x)) - ((v2->x - x) * (v0->z - z)))))) {
        return true;
    }

    if (((-detMax <= (detv0v1 = ((v0->z - z) * (v1->x - x)) - ((v0->x - x) * (v1->z - z)))) &&
         (-detMax <= (detv1v2 = ((v1->z - z) * (v2->x - x)) - ((v1->x - x) * (v2->z - z)))) &&
         (-detMax <= (detv2v0 = ((v2->z - z) * (v0->x - x)) - ((v2->x - x) * (v0->z - z)))))) {
        return true;
    }

    if ((fabsf(ny) > 0.5f) && (chkDistSq > 0.0f)) {
        
        if (Math3D_PointDistSqToLineZX(z, x, v0, v1, &distToEdgeSq) && (distToEdgeSq < chkDistSq)) {
            return true;
        }
        if (Math3D_PointDistSqToLineZX(z, x, v1, v2, &distToEdgeSq) && (distToEdgeSq < chkDistSq)) {
            return true;
        }
        if (Math3D_PointDistSqToLineZX(z, x, v2, v0, &distToEdgeSq) && (distToEdgeSq < chkDistSq)) {
            return true;
        }
    }
    return false;
}
