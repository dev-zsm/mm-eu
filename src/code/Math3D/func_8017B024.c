#include "types.h"

extern f32 D_801F35B8[];

s32 Math3D_PlaneVsPlaneNewLine(f32, f32, f32, f32, f32, f32, f32, f32, f32 *);
void Math3D_LineClosestToPoint(f32 *, f32 *, f32 *);

s32 Math3D_PlaneVsPlaneVsLineClosestPoint(f32 planeAA, f32 planeAB, f32 planeAC, f32 planeADist, f32 planeBA,
                                          f32 planeBB, f32 planeBC, f32 planeBDist, f32 *point, f32 *closestPoint) {
    if (!Math3D_PlaneVsPlaneNewLine(planeAA, planeAB, planeAC, planeADist, planeBA, planeBB, planeBC, planeBDist,
                                    D_801F35B8)) {
        return 0;
    }
    Math3D_LineClosestToPoint(D_801F35B8, point, closestPoint);
    return 1;
}
