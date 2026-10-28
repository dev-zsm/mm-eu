#include "types.h"
// FLAGS: -O2 -g0 -mips2
typedef struct { u8 pad[0xD5C]; s8 v; } S;
void func_80006B18(S *p) { if (p->v > 0 && p->v < 0x14) p->v = 0x14; }
