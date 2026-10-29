#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f p;
    Vec3f d;
} Line;

extern f32 D_801D79CC;
extern f32 Math3D_Vec3fMagnitudeSq(Vec3f *);
extern void Math_Vec3f_Copy(Vec3f *, Vec3f *);
float fabsf(float);
#pragma intrinsic (fabsf)

f32 Math3D_LineClosestToPoint(Line *line, Vec3f *pos, Vec3f *closest) {
    f32 lenSq;
    f32 t;

    lenSq = Math3D_Vec3fMagnitudeSq(&line->d);
    if (fabsf(lenSq) < D_801D79CC) {
        Math_Vec3f_Copy(closest, pos);
    }
    t = ((pos->x - line->p.x) * line->d.x + (pos->y - line->p.y) * line->d.y + (pos->z - line->p.z) * line->d.z) / lenSq;
    closest->x = line->d.x * t + line->p.x;
    closest->y = line->d.y * t + line->p.y;
    closest->z = line->d.z * t + line->p.z;
    return t;
}
