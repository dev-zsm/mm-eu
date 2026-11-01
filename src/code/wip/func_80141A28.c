// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;

typedef struct {
    u8 pad0[0xC];
    u32 unkC;
    u32 unk10;
} Fog;

extern void VisFbuf_SetBgSimple();

void VisFbuf_DrawInterpolate(Fog *a0, Gfx **a1, s32 a2, s32 a3, s32 a4) {
    Gfx *g;

    g = *a1;
    g->w1 = 0; g->w0 = 0xE7000000; g++;
    g->w1 = 0x404340; g->w0 = 0xEF000CF0; g++;
    g->w1 = a0->unkC; g->w0 = 0xFA000000; g++;
    g->w1 = a0->unk10; g->w0 = 0xFB000000; g++;
    g->w1 = 0x5566DB6D; g->w0 = 0xFC30B261; g++;
    VisFbuf_SetBgSimple(&g, a2, a2, a3, a4, 0);
    g->w1 = 0; g->w0 = 0xE7000000; g++;
    *a1 = g;
}
