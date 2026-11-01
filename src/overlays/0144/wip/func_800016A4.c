#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x70]; f32 a70; u8 p1[0x27C]; void *a2F0; u8 p2[8]; s16 a2FC; } S;
extern u8 D_8090FAC4[];
void func_800016A4(S *p) { p->a2FC = 0; p->a2F0 = D_8090FAC4; p->a70 = 0.0f; }
