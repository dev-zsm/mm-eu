#include "types.h"
typedef struct { u8 p[0xD0]; u8 u; } S;
void func_80000DD8(S *a0, s32 a1) { u8 t = a0->u + a1; a0->u = t; if (t >= 0x3D) a0->u = 0x3C; }
