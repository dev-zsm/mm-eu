// FLAGS: -O2 -g3 -mips2
#include "types.h"

void BgCheck_SphVsFirstPolyImpl(s32, s32, s32 *, s32 *, s32, f32, s32, s32);

void BgCheck_SphVsFirstWall(s32 arg0, s32 arg1, f32 arg2) {
    s32 sp2C;
    s32 sp28;

    BgCheck_SphVsFirstPolyImpl(arg0, 0, &sp2C, &sp28, arg1, arg2, 0, 5);
}
