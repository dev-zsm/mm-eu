// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[8];
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
} SkelCurve;

void SkelCurve_SetAnim(SkelCurve *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    arg0->unkC = arg2 - arg0->unk14;
    arg0->unk10 = arg3;
    arg0->unk18 = arg4;
    arg0->unk14 = arg5;
    arg0->unk8 = arg1;
}
