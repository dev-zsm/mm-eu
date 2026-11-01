// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2C0];
    Gfx *polyXlu;
} GraphicsContext;

typedef struct {
    GraphicsContext *gfxCtx;
} PlayState;

extern Gfx D_801C2060[];
void *Matrix_Finalize(GraphicsContext *gfxCtx);

void Gfx_DrawDListXlu(PlayState *play, Gfx *dList) {
    Gfx *gfx;
    GraphicsContext *gfxCtx;

    gfxCtx = play->gfxCtx;
    gfx = gfxCtx->polyXlu;
    {
        Gfx *g = &gfx[0];

        g->w0 = 0xDE000000;
        g->w1 = (u32)D_801C2060;
    }
    gfx[1].w0 = 0xDA380003;
    gfx[1].w1 = (u32)Matrix_Finalize(play->gfxCtx);
    gfx[2].w0 = 0xDE000000;
    gfx[2].w1 = (u32)dList;
    gfxCtx->polyXlu = gfx + 3;
}
