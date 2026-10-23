// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void CollisionCheck_LineOC();
void CollisionCheck_LineOCCheckAll(s32 a0, s32 a1, s32 a2, s32 a3) { CollisionCheck_LineOC(a0, a1, a2, a3, 0, 0); }
