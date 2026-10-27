// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

extern f32 D_801D79B0;
extern f32 D_801D79B4;
extern s32 func_800886B0(u16 arg0);

f32 Math_SinF(f32 rad) {
    return func_800886B0((s16)(rad * D_801D79B0)) * D_801D79B4;
}
