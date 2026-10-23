#include "types.h"

extern u16 D_801C9F00[];

u16 func_80180F40(f32 a0, f32 a1) {
    s32 idx = (a0 / a1) * 1024.0f;
    return D_801C9F00[idx];
}
