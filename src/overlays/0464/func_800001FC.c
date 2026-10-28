#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x34]; s16 a34; u8 p1[2]; u8 a38; u8 p2[0x10B]; void *a144; } S;
extern u8 D_80AFEC90[];
void func_800001FC(S *p, s32 a1) { p->a38 = p->a34; p->a144 = D_80AFEC90; }
