// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80085074(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
s32 func_80086E68(s32 a0);

s32 func_80085140(s32 a0, s32 a1, s32 a2, s32 a3, ...) {
    s32 ret;

    ret = func_80086E68(a3 - a2);
    if (ret != 0) {
        func_80085074(a0, a1, a2, a3, ret);
    }
    return ret;
}
