#include "types.h"
typedef struct { s16 x, y, z; } Vec3s;
typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 count; u8 pad1[3]; void *points; } Path;
extern Vec3s *func_80100304(void *);

s32 SubS_CopyPointFromPathCheckBounds(Path *path, s32 idx, Vec3f *dst) {
    Vec3s *pt;
    Vec3s *base;

    if (path == 0 || idx >= path->count || idx < 0) {
        return 0;
    }
    base = func_80100304(path->points);
    pt = (Vec3s *)(idx * 6 + (s32)base);
    dst->x = pt->x;
    dst->y = pt->y;
    dst->z = pt->z;
    return 1;
}
