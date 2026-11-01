// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"
void Math3D_SphVsCylOverlap(s32 a0, s32 a1, s32 a2) { s32 sp1C; Math3D_SphVsCylOverlapCenterDist(a0, a1, a2, &sp1C); }
