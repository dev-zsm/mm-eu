#include "types.h"
typedef struct { s16 x, y, z; } V;
typedef struct { u8 p0[0x30]; V v30; u8 p1[0x86]; V vBC; } S;
void func_80000348(S *a0, s32 a1) { a0->vBC = a0->v30; }
