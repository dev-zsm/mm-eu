// FLAGS: -O2 -g0 -mips2
#include "types.h"
void CollisionCheck_ClearContext(s32);
void CollisionCheck_InitContext(s32 a0, s16 *a1) { a1[1] = 0; CollisionCheck_ClearContext(a0); }
