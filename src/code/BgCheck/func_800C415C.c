// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 b[16];
} Blk;

f32 BgCheck_RaycastFloorImpl(s32 a0, s32 a1, s32 a2, Blk **out, s32 a4, s32 a5, s32 a6, s32 a7, f32 a8, s32 a9);

f32 BgCheck_AnyRaycastFloor2(s32 colCtx, Blk *dst, s32 pos, s32 pad) {
    Blk *poly;
    f32 y;

    y = BgCheck_RaycastFloorImpl(0, colCtx, 0, &poly, pos, pad, 0, 0x1C, 1.0f, 0);
    if (poly != 0) {
        *dst = *poly;
    }
    return y;
}
