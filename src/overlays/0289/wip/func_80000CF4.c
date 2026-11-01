#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x144]; u8 a144; u8 p1[0x53]; void *a198; } S;
extern u8 D_809D7B64[];
void func_80000CF4(S *p, s32 a1) { p->a198 = D_809D7B64; p->a144 = 1; }
