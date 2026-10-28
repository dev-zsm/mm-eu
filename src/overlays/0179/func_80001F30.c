#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { s16 p[0x118 / 2]; s16 a118; } T;
typedef struct { u8 p0[0x124]; T *a124; u8 p1[0xAC]; void *a1D4; } S;
extern u8 D_80948120[];
void func_80001F30(S *p) { p->a124->a118 = 10; p->a1D4 = D_80948120; }
