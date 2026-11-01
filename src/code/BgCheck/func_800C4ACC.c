// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"


void BgCheck_EntitySphVsWall3(s32 a0, s32 a1, s32 a2, s32 a3, f32 f4, s32 s4C, s32 s50, s32 s54, f32 f6) {
    BgCheck_CheckWallImpl(a0, 2, a1, a2, a3, f4, s4C, s50, s54, f6, 0);
}
