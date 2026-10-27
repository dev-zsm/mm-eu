#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { s16 x, y, z; } Vec3s;
typedef struct {
    /* 0x0 */ u8 count;
    /* 0x1 */ u8 pad1[3];
    /* 0x4 */ void *points;
} Path;

extern Vec3s *func_80100304(void *seg);

void Path_CopyLastPoint(Path *path, Vec3f *dest) {
    Vec3s *pt;

    if (path != 0) {
        pt = &func_80100304(path->points)[path->count - 1];
        dest->x = pt->x;
        dest->y = pt->y;
        dest->z = pt->z;
    }
}
