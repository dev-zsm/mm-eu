// FLAGS: -O1 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern void Math_Vec3f_Diff(Vec3f *a, Vec3f *b, Vec3f *dest);
extern void Math3D_PointOnDirectedLine(Vec3f *a, Vec3f *dir, f32 t, f32 u);

void Math3D_LineSplitRatio(Vec3f *a, Vec3f *b, f32 t, f32 u) {
    Vec3f diff;

    Math_Vec3f_Diff(b, a, &diff);
    Math3D_PointOnDirectedLine(a, &diff, t, u);
}
