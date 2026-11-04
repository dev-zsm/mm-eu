// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_TriChkPointParaXImpl(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 y, f32 z, f32 detMax, f32 chkDist, f32 ny) {
    f32 detv0v1;
    f32 detv1v2;
    f32 detv2v0;
    f32 distToEdgeSq;
    f32 chkDistSq;

    
    if (!Math3D_CirSquareVsTriSquareYZ(v0, v1, v2, y, z, chkDist)) {
        return false;
    }

    
    chkDistSq = SQ(chkDist);
    if (((SQ(v0->y - y) + SQ(v0->z - z)) < chkDistSq) || ((SQ(v1->y - y) + SQ(v1->z - z)) < chkDistSq) ||
        ((SQ(v2->y - y) + SQ(v2->z - z)) < chkDistSq)) {
        return true;
    }

    
    
    if (((detMax >= (detv0v1 = ((v0->y - y) * (v1->z - z)) - ((v0->z - z) * (v1->y - y)))) &&
         (detMax >= (detv1v2 = ((v1->y - y) * (v2->z - z)) - ((v1->z - z) * (v2->y - y)))) &&
         (detMax >= (detv2v0 = ((v2->y - y) * (v0->z - z)) - ((v2->z - z) * (v0->y - y)))))) {
        return true;
    }
    if (((-detMax <= (detv0v1 = ((v0->y - y) * (v1->z - z)) - ((v0->z - z) * (v1->y - y)))) &&
         (-detMax <= (detv1v2 = ((v1->y - y) * (v2->z - z)) - ((v1->z - z) * (v2->y - y)))) &&
         (-detMax <= (detv2v0 = ((v2->y - y) * (v0->z - z)) - ((v2->z - z) * (v0->y - y)))))) {
        return true;
    }

    if ((fabsf(ny) > 0.5f) && (chkDistSq > 0.0f)) {
        
        if ((Math3D_PointDistSqToLineYZ(y, z, v0, v1, &distToEdgeSq) != 0) && (distToEdgeSq < chkDistSq)) {
            return true;
        }
        if ((Math3D_PointDistSqToLineYZ(y, z, v1, v2, &distToEdgeSq) != 0) && (distToEdgeSq < chkDistSq)) {
            return true;
        }
        if ((Math3D_PointDistSqToLineYZ(y, z, v2, v0, &distToEdgeSq) != 0) && (distToEdgeSq < chkDistSq)) {
            return true;
        }
    }
    return false;
}
