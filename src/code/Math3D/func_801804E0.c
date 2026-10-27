// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void Math3D_CylVsCylOverlapCenterDist();
void Math3D_CylVsCylOverlap(s32 a0, s32 a1, s32 a2) { s32 loc; Math3D_CylVsCylOverlapCenterDist(a0, a1, a2, &loc); }
