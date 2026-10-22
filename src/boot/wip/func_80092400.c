// FLAGS: -O2 -g0 -mips2
#include "types.h"
void sins(s32 a, s32 b);
void coss(s32 arg0) { s32 *p = &arg0; sins((u16)(*p + 0x4000), *p); }
