// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 BgCheck_CheckWallImpl(s32, s32, s32, s32, s32, f32, s32, s32, s32, f32, s32);

void BgCheck_EntitySphVsWall3(s32 a0, s32 a1, s32 a2, s32 a3, f32 f4, s32 s4C, s32 s50, s32 s54, f32 f6) {
    BgCheck_CheckWallImpl(a0, 2, a1, a2, a3, f4, s4C, s50, s54, f6, 0);
}
