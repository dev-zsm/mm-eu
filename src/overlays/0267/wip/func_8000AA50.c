#include "types.h"
typedef struct { u8 pad[0x2B4]; u32 *p; } A;
u32 *func_8000AA50(A *s) { u32 *p; s->p -= 4; p = s->p; p[0] = 0xDF000000; p[1] = 0; return p; }
