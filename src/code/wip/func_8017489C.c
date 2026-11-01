// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2A0];
    Gfx *unk2A0;
    u8 pad2A4[0x2B0 - 0x2A4];
    Gfx *unk2B0;
} GraphicsContext;

Gfx *Gfx_Open(Gfx *gfx);
void Gfx_Close(Gfx *gfx, Gfx *dst);

void GameState_DrawEnd(GraphicsContext *gfxCtx) {
    Gfx *newDList;
    Gfx *gfx;

    gfx = gfxCtx->unk2B0;
    newDList = Gfx_Open(gfx);
    {
        Gfx *dl = gfxCtx->unk2A0++;

        dl->w0 = 0xDE000000;
        dl->w1 = (u32)newDList;
    }
    {
        Gfx *dl = newDList++;

        dl->w0 = 0xDF000000;
        dl->w1 = 0;
    }
    Gfx_Close(gfx, newDList);
    gfxCtx->unk2B0 = newDList;
}
