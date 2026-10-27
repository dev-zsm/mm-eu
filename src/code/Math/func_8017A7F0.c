// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

extern f32 D_801D79B8;
extern f32 D_801D79BC;

s32 func_80092400(u16 angle);

f32 Math_CosF(f32 rad) {
    return func_80092400((s16)(rad * D_801D79B8)) * D_801D79BC;
}
