// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void CollisionCheck_LineOC();
void CollisionCheck_LineOCCheck(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    CollisionCheck_LineOC(a0, a1, a2, a3, a4, a5);
}
