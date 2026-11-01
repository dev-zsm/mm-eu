#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpa;
    u8 pad2B4[0xC];
    Gfx *polyXlu;
} GfxCtx;

typedef struct {
    GfxCtx *gfxCtx;
} GameState;

extern u8 D_801C4820[];

void Scene_DrawConfigDefault(GameState *state) {
    GfxCtx *gfxCtx = state->gfxCtx;
    Gfx *dl;

    dl = gfxCtx->polyOpa++;
    dl->w1 = (u32)D_801C4820;
    dl->w0 = 0xDE000000;

    dl = gfxCtx->polyXlu++;
    dl->w1 = (u32)D_801C4820;
    dl->w0 = 0xDE000000;
}
