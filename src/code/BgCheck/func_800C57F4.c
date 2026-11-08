// FLAGS: -O2 -g3 -mips2
#include "types.h"

void BgCheck_SphVsFirstPolyImpl(s32, s32, s32 *, s32 *, s32, f32, s32, s32);

s32 BgCheck_SphVsFirstWall(struct CollisionContext *colCtx, struct Vec3f *center, f32 radius) {
    s32 sp2C;
    s32 sp28;

    BgCheck_SphVsFirstPolyImpl(colCtx, 0, &sp2C, &sp28, center, radius, 0, 5);
}
