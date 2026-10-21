// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"
extern u8 *D_8009C220;
s32 func_800848CC(s32 a0, s32 a1, s32 a2);
void func_80083BD0(s32 a0, s32 a1, s32 a2) { u16 x = a1; u16 y = a2; *(s32 *)(D_8009C220 + 0x844) = a0; func_800848CC(a0, x, y); }
