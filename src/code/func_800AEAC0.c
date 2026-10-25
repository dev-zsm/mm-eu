#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *dlHead;
} GraphicsContext;

extern Gfx *Play_SetFog(GraphicsContext **gfxCtxPtr, Gfx *dl);

void func_800AEAC0(GraphicsContext **gfxCtxPtr) {
    s32 pad; // keeps the spill slot of gfxCtx at 0x18
    GraphicsContext *gfxCtx = *gfxCtxPtr;

    // One-line command: the ROM schedules the lui after the load only for a single-line emit.
    { Gfx *_g = gfxCtx->dlHead++; _g->w0 = 0xE7000000; _g->w1 = 0; }
    gfxCtx->dlHead = Play_SetFog(gfxCtxPtr, gfxCtx->dlHead);
}
