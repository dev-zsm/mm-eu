#include "types.h"
// FLAGS: -O2 -g0 -mips2
extern void func_8082E0E8(s32 a0, s32 a1, s32 a2, s32 a3);
void func_80000FD0(s32 a0, s32 a1, s32 a2) { func_8082E0E8(a0, a1, a2, 0x20C); }
