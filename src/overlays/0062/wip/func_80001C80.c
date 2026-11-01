#include "types.h"
typedef struct { u8 pad[0x2B4]; u32 *g; } A;
u32 *func_80001C80(A *a) { u32 *p = a->g - 4; a->g = p; *p++ = 0xDF000000; *p = 0; return p - 1; }
