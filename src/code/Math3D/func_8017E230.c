// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern f32 D_801D7A20;
s32 Math3D_TriChkPointParaZImpl(s32, s32, s32, s32, f32, f32, f32, f32);
f32 fabsf(f32);
#pragma intrinsic (fabsf)

typedef struct {
    u8 pad0[8];
    f32 unk8;
} Vec8017E230;

s32 Math3D_TriChkLineSegParaZDist(s32 a0, s32 a1, s32 a2, Vec8017E230 *a3, s32 p5, f32 p6, f32 p7) {
    f32 f;

    f = a3->unk8;
    if (fabsf(f) < D_801D7A20) {
        return 0;
    }
    if (Math3D_TriChkPointParaZImpl(a0, a1, a2, p5, p6, 0.0f, p7, f) != 0) {
        return 1;
    }
    return 0;
}
