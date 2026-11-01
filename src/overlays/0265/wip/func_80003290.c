#include "types.h"
typedef struct { u32 w0; u32 w1; } G;
typedef struct { u8 pad0[0x2B4]; G *g; } A;
G *func_80003290(A *a) {
    G *p = a->g;
    G *q;
    p -= 2;
    a->g = p;
    p->w0 = 0xE200001C;
    p->w1 = 0xC81049F8;
    q = p + 1;
    q->w0 = 0xDF000000;
    q->w1 = 0;
    return p;
}
