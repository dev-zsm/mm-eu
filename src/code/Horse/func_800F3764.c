#include "types.h"

typedef struct { s16 x, y, z; } Vec3s;
typedef struct { u8 count; u8 pad[3]; Vec3s *points; } PathEntry;
typedef struct { u8 pad[0x18864]; PathEntry *paths; } Game;

extern Vec3s *func_80100304(void *);

s32 Horse_CopyPointFromPathList(Game *game, s32 pathIndex, s32 index, Vec3s *dst, s16 *out) {
    PathEntry *path = &game->paths[pathIndex];
    s32 count = path->count;
    Vec3s *p;

    dst->x = 0;
    dst->y = 0;
    dst->z = 0;
    *out = 0;
    if (count == 0) {
        return 0;
    }
    if (index >= count) {
        return 0;
    }
    p = (Vec3s *)((u8 *)func_80100304(path->points) + index * 6);
    dst->x = p->x;
    dst->y = p->y;
    dst->z = p->z;
    *out = 0;
    return 1;
}
