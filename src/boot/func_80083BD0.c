// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"
extern u8 *D_8009C220;
s32 func_800848CC(s32 a0, u16 a1, u16 a2);
void func_80083BD0(s32 a0, u16 a1, u16 a2) { *(s32 *)(D_8009C220 + 0x844) = a0; func_800848CC(a0, a1, a2); }
