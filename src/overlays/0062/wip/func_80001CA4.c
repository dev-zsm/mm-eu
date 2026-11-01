#include "types.h"
typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad[0x2B4]; Gfx *p; } A;
Gfx *func_80001CA4(A *a0) {
Gfx *p; Gfx *q; p = (Gfx *)((u8 *)a0->p - 0x10); a0->p = p; q = p; q->w0 = 0xE200001C; q->w1 = 0xC81049F8; q = p+1;q->w0 = 0xDF000000; q->w1 = 0; return p;
}
