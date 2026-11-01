#include "types.h"
typedef struct { u32 w0, w1; } G;
typedef struct { u8 p[0x2B4]; G *u; } S;
G *func_80003034(S *a0) { G *p = a0->u - 2; a0->u = p; p->w0 = 0xDF000000; p->w1 = 0; return a0->u; }
