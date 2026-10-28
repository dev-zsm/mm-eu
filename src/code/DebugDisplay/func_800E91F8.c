#include "types.h"

typedef struct DbgObj {
    f32 x, y, z;
    s16 rx, ry, rz;
    f32 sx, sy, sz;
    u8 r, g, b, a;
    s16 type;
    s16 pad26;
    struct DbgObj *next;
    s32 pad2C;
} DbgObj;

typedef struct {
    u8 pad0[0x2B4];
    DbgObj *tail;
} Game;

extern DbgObj *D_801EB7F0;

DbgObj *DebugDisplay_AddObject(f32 x, f32 y, f32 z, s16 rx, s16 ry, s16 rz, f32 sx, f32 sy, f32 sz, u8 r, u8 g, u8 b,
                               u8 a, s16 type, Game *game) {
    DbgObj *prev;

    prev = D_801EB7F0;
    D_801EB7F0 = game->tail = game->tail - 1;
    D_801EB7F0->x = x;
    D_801EB7F0->y = y;
    D_801EB7F0->z = z;
    D_801EB7F0->rx = rx;
    D_801EB7F0->ry = ry;
    D_801EB7F0->rz = rz;
    D_801EB7F0->sx = sx;
    D_801EB7F0->sy = sy;
    D_801EB7F0->sz = sz;
    D_801EB7F0->r = r;
    D_801EB7F0->g = g;
    D_801EB7F0->b = b;
    D_801EB7F0->a = a;
    D_801EB7F0->type = type;
    D_801EB7F0->next = prev;
    return D_801EB7F0;
}
