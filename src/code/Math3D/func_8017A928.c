// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_PlaneVsLineSegClosestPoint(f32 planeAA, f32 planeAB, f32 planeAC, f32 planeADist, f32 planeBA, f32 planeBB,
                                      f32 planeBC, f32 planeBDist, Vec3f* linePointA, Vec3f* linePointB,
                                      Vec3f* closestPoint) {
    static InfiniteLine sPlaneIntersectLine;
    static Linef sPlaneIntersectSeg;
    Vec3f sp34; 

    if (!Math3D_PlaneVsPlaneNewLine(planeAA, planeAB, planeAC, planeADist, planeBA, planeBB, planeBC, planeBDist,
                                    &sPlaneIntersectLine)) {
        
        return false;
    }

    
    Math_Vec3f_Copy(&sPlaneIntersectSeg.a, &sPlaneIntersectLine.point);
    sPlaneIntersectSeg.b.x = (sPlaneIntersectLine.dir.x * 100.0f) + sPlaneIntersectLine.point.x;
    sPlaneIntersectSeg.b.y = (sPlaneIntersectLine.dir.y * 100.0f) + sPlaneIntersectLine.point.y;
    sPlaneIntersectSeg.b.z = (sPlaneIntersectLine.dir.z * 100.0f) + sPlaneIntersectLine.point.z;

    
    if (!Math3D_LineSegMakePerpLineSeg(&sPlaneIntersectSeg.a, &sPlaneIntersectSeg.b, linePointA, linePointB,
                                       closestPoint, &sp34)) {
        return false;
    }
    return true;
}
