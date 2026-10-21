// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80085FA0(s32 a0, u8 *a1, s32 a2, s32 a3);

s32 func_80086054(s32 arg0, u8 *arg1, s32 arg2) {
    func_80085FA0(arg0, arg1, 1, arg2);
    return arg0;
}
