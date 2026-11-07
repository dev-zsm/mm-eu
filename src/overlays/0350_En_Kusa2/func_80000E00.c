#include "types.h"
typedef struct { u8 p[0xD0]; u8 u; } S;
void func_80000E00(S *a0, s32 a1) { s32 d = a0->u; d -= a1; if (d > 0) { a0->u = d; } else a0->u = 0; }
