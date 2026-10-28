#include "types.h"
typedef struct { u8 pad0[0x28]; s16 x, y, z, w; s16 dx, dy, dz, dw; f32 scale; u8 pad3C[4]; } E;
typedef struct { u8 pad0[0x18]; s32 count; E *tbl; } L;
typedef struct { u8 pad0[0x24]; f32 x, y, z; } S;
void func_800E7ED0(L *arg0, s32 arg1, S *arg2) {
    if (arg1 < arg0->count) {
        arg0->tbl[arg1].dx = arg0->tbl[arg1].x + arg2->x;
        arg0->tbl[arg1].dy = arg0->tbl[arg1].y + arg2->y;
        arg0->tbl[arg1].dz = arg0->tbl[arg1].z + arg2->z;
        arg0->tbl[arg1].dw = arg0->tbl[arg1].w * arg0->tbl[arg1].scale;
    }
}
