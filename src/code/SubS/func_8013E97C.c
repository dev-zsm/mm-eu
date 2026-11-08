#include "types.h"

typedef struct {
    f32 a, b, c, d;
} Plane;

extern void SubS_ConstructPlane(void *arg0, void *arg1, void *arg2, Plane *plane);
extern s32 Math3D_LineSegVsPlane(f32 a, f32 b, f32 c, f32 d, void *pointA, void *pointB, void *intersect, s32 fromFront);

s32 SubS_LineSegVsPlane(struct Vec3f *point, struct Vec3s *rot, struct Vec3f *unitVec, struct Vec3f *linePointA, struct Vec3f *linePointB, struct Vec3f *intersect) {
    s32 pad; // padding: matches the stack layout of the ROM
    Plane plane;

    SubS_ConstructPlane(point, unitVec, rot, &plane);
    return Math3D_LineSegVsPlane(plane.a, plane.b, plane.c, plane.d, linePointA, linePointB, intersect, 0) ? 1 : 0;
}
