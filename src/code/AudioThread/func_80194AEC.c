// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 func_80088070(s32, u32 *, s32);
extern u8 D_801FC8F9;
extern s32 D_801FFE38;
s32 func_80194AEC(void) {
    s32 pad;
    u32 sp18;
    if (func_80088070(D_801FFE38, &sp18, 0) == -1) {
        return 0;
    }
    if (sp18 != D_801FC8F9) {
        return -1;
    }
    return 1;
}
