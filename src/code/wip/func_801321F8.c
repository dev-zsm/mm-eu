#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpaHead;
    u8 pad2B4[0x2C0 - 0x2B4];
    Gfx *polyXluHead;
} GraphicsContext;

extern u32 D_801C4940[];

// One-line macro: the ROM's scheduling depends on the command being emitted from a single source line.
#define DISPLAY_LIST_CMD(pkt, arg) { Gfx *_g = (pkt); _g->w0 = 0xDB060030; _g->w1 = (arg); }

void Scene_SetCullFlag(GraphicsContext **gfxCtxPtr, s32 index, s32 flags) {
    u32 value;
    GraphicsContext *gfxCtx;

    value = D_801C4940[index];
    gfxCtx = *gfxCtxPtr;

    if (flags & 1) {
        DISPLAY_LIST_CMD(gfxCtx->polyOpaHead++, value);
    }
    if (flags & 2) {
        DISPLAY_LIST_CMD(gfxCtx->polyXluHead++, value);
    }
}
