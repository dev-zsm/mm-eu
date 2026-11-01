#include "types.h"
typedef struct { u32 w0; u32 w1; } G;
typedef struct { u8 pad[0x2B4]; G *unk2B4; } A;
G *func_80001CE4(A *a) {
    G *g = a->unk2B4 - 2;
    a->unk2B4 = g;
    g->w1 = 0xC8112078;
    g->w0 = 0xE200001C;
    (g + 1)->w0 = 0xDF000000;
    (g + 1)->w1 = 0;
    return g;
}
