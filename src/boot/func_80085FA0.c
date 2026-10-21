// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80085DE4(s32 a0, u8 a1);

void func_80085FA0(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 var_s1;
    u8 *var_s0;

    var_s0 = arg1;
    var_s1 = arg2 * arg3;
    while (var_s1 != 0) {
        func_80085DE4(arg0, *var_s0++);
        var_s1 -= 1;
    }
}
