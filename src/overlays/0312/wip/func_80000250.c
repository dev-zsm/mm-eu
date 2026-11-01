// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad[0x2B4]; Gfx *p; } S;

Gfx *func_80000250(S *a, s32 b) {
    Gfx *g = a->p;
    Gfx *h = g - 1;
    g -= 2;
    a->p = g;
    g->w0 = 0xFB000000;
    g->w1 = b & 0xFF;
    h->w0 = 0xDF000000;
    h->w1 = 0;
    return g;
}
