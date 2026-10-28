#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x70]; f32 a70; u8 p1[0x11C]; void *a190; } S;
extern u8 D_809895EC[];
void func_800006CC(S *p) { p->a190 = D_809895EC; p->a70 = 1.0f; }
