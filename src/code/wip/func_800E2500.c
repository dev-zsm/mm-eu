// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x138];
    s32 unk138;
} Owner;

typedef struct {
    Owner *owner;
    u8 pad4[0x11];
    u8 shape;
} Collider;

typedef struct {
    u8 pad0[2];
    u16 flags;
    u8 pad4[0xC8];
    s32 count;
    Collider *list[0x3C];
} ColCtx;

typedef s32 (*SetFunc)(void *, Collider *);
extern SetFunc D_801BAE7C[];
extern s32 func_8016B1A4(void *play, ColCtx *ctx);

s32 CollisionCheck_SetAC(void *play, ColCtx *ctx, Collider *col) {
    s32 idx;

    if (func_8016B1A4(play, ctx) != 0) {
        return -1;
    }
    D_801BAE7C[col->shape](play, col);
    if (col->owner != NULL && col->owner->unk138 == 0) {
        return -1;
    }
    idx = ctx->count;
    if (idx >= 0x3C) {
        return -1;
    }
    if (ctx->flags & 1) {
        return -1;
    }
    ctx->list[idx] = col;
    ctx->count++;
    return idx;
}
