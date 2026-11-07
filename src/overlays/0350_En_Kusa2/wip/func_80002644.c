#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x13C]; void *a13C; u8 p1[0x50]; void *a190; } S;
extern u8 D_80A43620[];
extern u8 D_80A42524[];
void func_80002644(S *p) { p->a13C = D_80A43620; p->a190 = D_80A42524; }
