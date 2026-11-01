#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpaHead;
    u8 pad2B4[0xC];
    Gfx *polyXluHead;
} GraphicsContext;

extern u32 D_801C4910[];

// One-line macro: the ROM's scheduling depends on the command being emitted from a single source line.
#define DISPLAY_LIST_CMD(pkt, value) { Gfx *_g = (pkt); _g->w0 = 0xDB060030; _g->w1 = (value); }

void Scene_SetRenderModeXlu(GraphicsContext **play, s32 index, s32 flags) {
    u32 mode = D_801C4910[index];
    GraphicsContext *gfxCtx = *play;

    if (flags & 1) {
        DISPLAY_LIST_CMD(gfxCtx->polyOpaHead++, mode);
    }
    if (flags & 2) {
        DISPLAY_LIST_CMD(gfxCtx->polyXluHead++, mode);
    }
}
