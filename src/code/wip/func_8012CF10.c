#include "types.h"

typedef struct { u32 w0, w1; } Gfx;

extern Gfx *Gfx_Alloc(void *, s32);

Gfx *Gfx_BranchTexScroll(void *gfx, u32 x, u32 y, s32 width, s32 height) {
    Gfx *dl = Gfx_Alloc(gfx, 0x18);
    Gfx *p = dl;

    p->w0 = 0xE8000000;
    p->w1 = 0;
    p++;
    p->w0 = 0xF2000000 | ((x & 0xFFF) << 12) | (y & 0xFFF);
    p->w1 = (((x + (width - 1) * 4) & 0xFFF) << 12) | ((y + (height - 1) * 4) & 0xFFF);
    p++;
    p->w0 = 0xDF000000;
    p->w1 = 0;
    p++;
    return dl;
}
