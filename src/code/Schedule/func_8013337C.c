// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 Schedule_BranchS(void *a0, u8 **a1, void *a2) { u8 *p = *a1; *a1 += *(s8 *)(p + 1); return 0; }
