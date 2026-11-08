// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80173B14(void *, s32);

union Vtx * THGA_AllocVtx(union TwoHeadGfxArena *thga) {
    func_80173B14(thga, 0x10);
}
