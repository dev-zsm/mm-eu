#include "types.h"

/* An 8-byte by-value argument: it makes the ROM spill a2/a3 and reload them for the call. */
typedef struct {
    s32 w0;
    s32 w1;
} Pair;

extern void Math3D_PointDistSqToLine2DImpl(s32 a0, s32 a1, s32 a2, s32 a3, f32 a4, f32 a5, f32 *out0, f32 *out1, s32 a6);

void Math3D_PointDistSqToLine2D(s32 a0, s32 a1, Pair p, f32 a4, f32 a5, s32 a6) {
    f32 out0;
    f32 out1;

    Math3D_PointDistSqToLine2DImpl(a0, a1, p.w0, p.w1, a4, a5, &out0, &out1, a6);
}
