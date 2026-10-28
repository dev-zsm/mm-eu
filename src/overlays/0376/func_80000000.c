#include "types.h"
// FLAGS: -O2 -g0 -mips2
extern void func_800897D0(s32 a0, s32 a1);
void func_80000000(s32 a0) { func_800897D0(a0, 0x1928); }
