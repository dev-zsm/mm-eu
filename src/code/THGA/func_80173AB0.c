// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 THA_AllocHead(s32, s32, s32);

union Gfx * THGA_AllocDisplayList(union TwoHeadGfxArena *thga, u32 num) {
    THA_AllocHead(thga, num * 8, num);
}
