#include "types.h"

extern void Gfx_TexScroll(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_8012CFD8(s32 arg0, s32 arg1, s32 arg2) {
    Gfx_TexScroll(arg0, arg1, arg2, 0, 0);
}
