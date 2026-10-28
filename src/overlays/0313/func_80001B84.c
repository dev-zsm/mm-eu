#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[4]; u32 a4; u8 p1[0x13C]; void *a144; } S;
extern u8 D_80A15674[];
void func_80001B84(S *p) { p->a4 |= 0x10; p->a144 = D_80A15674; }
