#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { s16 x, y, z; } Vec3s;
typedef struct {
    /* 0x0 */ u8 count;
    /* 0x1 */ u8 pad1[3];
    /* 0x4 */ void *points;
} Path;

extern Vec3s *func_80100304(void *seg);

s32 SubS_CopyPointFromPath(Path *path, s32 index, Vec3f *dest) {
    Vec3s *pt;
    Vec3s *pts;

    if (path == 0) {
        return 0;
    }
    pts = func_80100304(path->points); pt = (Vec3s *)((u32)index * 6 + (u32)pts);
    dest->x = pt->x;
    dest->y = pt->y;
    dest->z = pt->z;
    return 1;
}
