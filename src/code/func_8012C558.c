#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *dlHead;
} GraphicsContext;

extern u8 D_801C2510[];

// One-line macro: the ROM's scheduling depends on the command being emitted from a single source line.
#define DISPLAY_LIST_CMD(pkt, dl) { Gfx *_g = (pkt); _g->w0 = 0xDE000000; _g->w1 = (u32)(dl); }

void func_8012C558(GraphicsContext *gfxCtx) {
    DISPLAY_LIST_CMD(gfxCtx->dlHead++, D_801C2510);
}
