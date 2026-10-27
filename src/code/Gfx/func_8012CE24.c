#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2C0];
    Gfx *dlHead;
} GraphicsContext;

extern u8 D_801C26F0[];

// One-line macros: the ROM's scheduling depends on each command being emitted from a single source line.
#define DISPLAY_LIST_CMD(pkt, dl) { Gfx *_g = (pkt); _g->w0 = 0xDE000000; _g->w1 = (u32)(dl); }
#define GEOMETRY_MODE_CMD(pkt) { Gfx *_g = (pkt); _g->w0 = 0xE3001801; _g->w1 = 0xC0; }

void Gfx_SetupDL60_XluNoCD(GraphicsContext *gfxCtx) {
    DISPLAY_LIST_CMD(gfxCtx->dlHead++, D_801C26F0);
    GEOMETRY_MODE_CMD(gfxCtx->dlHead++);
}
