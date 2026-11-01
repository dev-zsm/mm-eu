#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 p0[0x15C]; void *a15C; u8 p1[0xC]; u8 a16C, a16D, a16E; } S;
extern u8 D_80920A60[];
void func_80001380(S *p) { p->a16C = 0; p->a16D = 0; p->a16E = 0; p->a15C = D_80920A60; }
