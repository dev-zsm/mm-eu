// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 b[16]; } Poly;
f32 BgCheck_RaycastFloorImpl(s32, void *, s32, Poly **, void *, void *, s32, s32, f32, s32);
f32 BgCheck_AnyRaycastFloor1(void *colCtx, Poly *outPoly, void *pos) {
    Poly *poly;
    u8 sp34[8];
    f32 r;
    r = BgCheck_RaycastFloorImpl(0, colCtx, 0, &poly, sp34, pos, 0, 0x1C, 1.0f, 0);
    if (poly != 0) {
        *outPoly = *poly;
    }
    return r;
}
