// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Skin_DrawImpl(s32, s32, s32, s32, s32, s32, s32, s32);

void func_801385D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Skin_DrawImpl(arg0, arg1, arg2, arg3, 0, arg4, 0, 0);
}
