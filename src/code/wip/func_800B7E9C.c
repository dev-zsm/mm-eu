// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B4];
    Gfx *unk2B4;
    u8 pad2B8[8];
    Gfx *unk2C0;
} GfxCtx;

typedef struct {
    s32 x;
    s32 y;
} Pt;

Pt *func_800BC9EC(void *);

void func_800B7E9C(u8 *arg0, GfxCtx **arg1, s32 arg2) {
    Pt *p;
    Gfx *d;
    Gfx *g;

    p = func_800BC9EC(arg0 + 0x24);
    if (arg2 != 0) {
        d = (*arg1)->unk2B4 - 2;
        (*arg1)->unk2B4 = d;
        d[0].w0 = 0xF2000000 | ((p->x & 0xFFF) << 12) | (p->y & 0xFFF);
        d[0].w1 = 0x01000000 | (((p->x + 0x3C) & 0xFFF) << 12) | ((p->y + 0x3C) & 0xFFF);
        d[1].w0 = 0xDF000000;
        d[1].w1 = 0;
        g = (*arg1)->unk2C0;
        (*arg1)->unk2C0 = g + 1;
        g->w1 = (u32)d;
        g->w0 = 0xDB06001C;
    }
}
