// FLAGS: -O2 -g3 -mips2
// best attempt (18/28 differ): ROM computes ((x&0xFFFF)>>4)&0xFFFF into t6..t8 without a prologue andi; ours adds the u16-param conversion in the prologue
#include "types.h"
extern s16 D_800977D0[];
s16 sins(u16 x) { s16 v; x = (u32)x >> 4; if (x & 0x400) { v = D_800977D0[0x3FF - (x & 0x3FF)]; } else { v = D_800977D0[x & 0x3FF]; } if (x & 0x800) { return -v; } return v; }
