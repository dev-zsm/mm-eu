#include "types.h"
typedef struct { u32 w0; u32 w1; } G;
typedef struct { u8 pad[0x2B4]; G *p; } A;
G *func_80003B34(A *a0) { G *g = a0->p - 2; a0->p = g; g->w0 = 0xDF000000; g->w1 = 0; return g; }
