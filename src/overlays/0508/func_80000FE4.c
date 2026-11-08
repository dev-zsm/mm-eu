// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801C9EE0[];
extern u8 D_80B5C38C[];
void func_80182B28();

s32 func_80000FE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (arg1 == 0x15) {
        func_80182B28(D_801C9EE0, arg5 + 0x35C, arg1);
    }
    if (arg1 == 0x15) {
        func_80182B28(D_80B5C38C, arg5 + 0x350, arg1);
    }
    return 0;
}
