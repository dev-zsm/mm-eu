// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_8017A1B0(s32, s32, s32, s32);

void func_8017A1E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_8017A1B0(arg0, arg1, arg2, arg3 * 4228 + 0x843);
}
