#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x1A8]; f32 a1A8; u8 p1[8]; f32 a1B4; u8 p2[0xC]; f32 a1C4; } S;
void func_8000061C(S *p) { p->a1B4 = 1.0f; p->a1C4 = 1.0f; p->a1A8 = 1.0f; }
