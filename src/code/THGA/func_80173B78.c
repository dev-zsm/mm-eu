// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80173B14(s32, s32, s32);

union Vtx * THGA_AllocVtxArray(union TwoHeadGfxArena *thga, u32 num) {
    func_80173B14(thga, num << 4, num);
}
