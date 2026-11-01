#include "types.h"

typedef struct { u32 w0, w1; } Gfx;

void View_SetScissor(Gfx **gfxp, s32 ulx, s32 uly, s32 lrx, s32 lry) {
    Gfx *g = *gfxp;
    Gfx *gfx = g++;

    gfx->w0 = 0xED000000 | (((s32)(ulx * 4.0f) & 0xFFF) << 12) | ((s32)(uly * 4.0f) & 0xFFF);
    gfx->w1 = (((s32)(lrx * 4.0f) & 0xFFF) << 12) | ((s32)(lry * 4.0f) & 0xFFF);
    *gfxp = g;
}
