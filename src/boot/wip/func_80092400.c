// FLAGS: -O2 -g0 -mips2
#include "types.h"
s16 sins(u16 x);
s16 coss(s16 x) { return sins(x + 0x4000); }
