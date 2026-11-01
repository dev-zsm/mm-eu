// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x2B0];
    u32 *dlA;
    u32 *dlB;
} GfxCtx;

typedef struct {
    s32 x;
    s32 y;
} Pt;

typedef struct { u8 pad0[0x24]; u8 unk24; } Play;
extern Pt *func_800BC978(void *);

void func_800B7DD4(Play *a0, GfxCtx **a1, s32 a2) {
    Pt *pt;
    u32 *gfx;
    GfxCtx *g;
    u32 *p;

    pt = func_800BC978(&a0->unk24);
    if (a2 != 0) {
        (*a1)->dlB = (*a1)->dlB - 4;
        gfx = (*a1)->dlB;
        g = *a1;
        gfx[0] = ((pt->x & 0xFFF) << 12) | 0xF2000000 | (pt->y & 0xFFF);
        gfx[1] = (((pt->x + 0x3C) & 0xFFF) << 12) | 0x01000000 | ((pt->y + 0x3C) & 0xFFF);
        gfx[2] = 0xDF000000;
        gfx[3] = 0;
        p = g->dlA;
        g->dlA = p + 2;
        p[1] = (u32)gfx;
        p[0] = 0xDB06001C;
    }
}
