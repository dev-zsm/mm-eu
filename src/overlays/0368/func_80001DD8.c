#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[4]; u32 a4; u8 p1[0x19C]; void *a1A4; } S;
extern u8 D_80A67C48[];
void func_80001DD8(S *p) { p->a4 |= 0x10; p->a1A4 = D_80A67C48; }
