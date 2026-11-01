#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x32]; s16 a32; u8 p1[0x8A]; s16 aBE; u8 p2[0x110]; void *a1D0; u8 p3[6]; s16 a1DA; } S;
extern u8 D_808ACDAC[];
void func_80000D4C(S *p) { p->a32 = p->aBE; p->a1DA = 0; p->a1D0 = D_808ACDAC; }
