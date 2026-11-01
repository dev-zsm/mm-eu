// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x4];
    Gfx *dl;
    u8 pad8[0x8];
    u32 unk10;
} Ctx;

extern u8 D_80096E98[];
extern u8 D_80096DF0[];
extern u8 D_80096E90[];
extern u8 D_80096E70[];

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define T(w) MAX(1, (w) / 16)
#define GFX_NEXT (g = ctx->dl, ctx->dl = g + 1)

void GfxPrint_Setup(Ctx *ctx) {
    Gfx *g;
    s32 a1;
    s32 i;
    s32 width = 16;
    s32 height = 256;
    s32 d;
    s32 q;
    s32 s0;
    s32 s1;
    s32 t4;
    s32 a3;
    s32 lrs;
    Gfx *p6;

    GFX_NEXT;
    g->w1 = 0;
    g->w0 = 0xE7000000;

    GFX_NEXT;
    g->w0 = 0xEF00ECF0;
    g->w1 = 0x00504244;

    GFX_NEXT;
    g->w0 = 0xFCFFFFFF;
    g->w1 = 0xFFFCF279;

    GFX_NEXT;
    g->w0 = 0xFD500000;
    g->w1 = (u32)D_80096E98;

    GFX_NEXT;
    g->w0 = 0xF5500000;
    g->w1 = 0x07000000;

    GFX_NEXT;
    g->w0 = 0xE6000000;
    g->w1 = 0;

    GFX_NEXT;
    g->w1 = ((((2047 + T(width)) / T(width)) & 0xFFF) | 0x07000000) | ((MIN((((width * height + 3) >> 2) - 1), 2047) & 0xFFF) << 12);
    g->w0 = 0xF3000000;

    a1 = 0xF5400200;
    GFX_NEXT;
    g->w1 = 0;
    g->w0 = 0xE7000000;

    GFX_NEXT;
    g->w1 = 0;
    g->w0 = a1;

    GFX_NEXT;
    g->w1 = 0x0003C3FC;
    g->w0 = 0xF2000000;

    GFX_NEXT;
    g->w1 = (u32)D_80096DF0;
    g->w0 = 0xFD100000;

    GFX_NEXT;
    g->w1 = 0;
    g->w0 = 0xE8000000;

    GFX_NEXT;
    g->w1 = 0x07000000;
    g->w0 = 0xF5000100;

    s0 = 2;

    GFX_NEXT;
    g->w1 = 0x070FC000;
    g->w0 = 0xE6000000;

    t4 = 1;

    GFX_NEXT;
    g->w1 = 0x070FC000;
    g->w0 = 0xF0000000;

    GFX_NEXT;
    g->w1 = 0;
    g->w0 = 0xE7000000;

    for (i = 1; i < 4; i++) {
        GFX_NEXT;
        g->w1 = (((i * 2) & 7) << 24) | ((i & 0xF) << 20);
        g->w0 = 0xF5400200;
        GFX_NEXT;
        g->w1 = ((((i * 2) & 7) << 24) | 0x3C000) | 0x3FC;
        g->w0 = 0xF2000000;
    }

    GFX_NEXT;
    g->w0 = 0xFA000000;
    g->w1 = ctx->unk10;

    GFX_NEXT;
    g->w0 = 0xFD480000;
    g->w1 = (u32)D_80096E90;

    GFX_NEXT;
    g->w0 = 0xF5480200;
    g->w1 = 0x0700C010;

    GFX_NEXT;
    g->w1 = 0;
    g->w0 = 0xE6000000;

    GFX_NEXT;
    g->w0 = 0xF4000000;
    g->w1 = 0x0700201C;

    GFX_NEXT;
    g->w1 = 0;
    g->w0 = 0xE7000000;

    GFX_NEXT;
    g->w1 = 0x0140C010;
    g->w0 = 0xF5400200;

    GFX_NEXT;
    g->w1 = 0x0100401C;
    g->w0 = 0xF2000000;

    GFX_NEXT;
    g->w1 = (u32)D_80096E70;
    g->w0 = 0xFD100000;

    GFX_NEXT;
    g->w1 = 0;
    g->w0 = 0xE8000000;

    GFX_NEXT;
    g->w1 = 0x07000000;
    g->w0 = 0xF5000140;

    GFX_NEXT;
    g->w0 = 0xE6000000;
    g->w1 = 0;

    GFX_NEXT;
    g->w1 = 0x0703C000;
    g->w0 = 0xF0000000;

    GFX_NEXT;
    g->w0 = 0xE7000000;
    g->w1 = 0;

    for (i = 1; i < 4; i++) {
        GFX_NEXT;
        g->w1 = (((i * 2 + 1) & 7) << 24) | 0x40C010;
        g->w0 = 0xF5400200;
        GFX_NEXT;
        g->w1 = (((i * 2 + 1) & 7) << 24) | 0x401C;
        g->w0 = 0xF2000000;
    }
}
