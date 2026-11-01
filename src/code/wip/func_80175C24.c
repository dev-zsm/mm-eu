#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

void *Gfx_Alloc(Gfx **gfxp, u32 size) {
    Gfx *gfx = *gfxp;
    void *data = gfx + 1;

    size = (size + 7) & ~7;
    gfx->w0 = 0xDE010000;
    gfx->w1 = (u32)data + size;
    *gfxp = (Gfx *)gfx->w1;
    return data;
}
