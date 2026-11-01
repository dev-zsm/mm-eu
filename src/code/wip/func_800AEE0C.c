#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2C0];
    Gfx *dlHead;
} GraphicsContext;

typedef struct {
    GraphicsContext *gfxCtx;
} Context;

extern Gfx *Play_SetFog(Context *ctx, Gfx *dl);

// One-line macro: the ROM's scheduling depends on the command being emitted from a single source line.
#define GSET_CMD(pkt, c0, c1) { Gfx *_g = (pkt); _g->w0 = (c0); _g->w1 = (c1); }

void func_800AEE0C(Context *ctx) {
    GraphicsContext *gfxCtx = ctx->gfxCtx;

    GSET_CMD(gfxCtx->dlHead++, 0xE7000000, 0);
    gfxCtx->dlHead = Play_SetFog(ctx, gfxCtx->dlHead);
}
