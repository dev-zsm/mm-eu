// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_8008E1F0(s32 a0, void *a1, s32 a2, s32 a3);

void func_80087AA0(s32 *arg0, s32 arg1, s32 arg2) {
    func_8008E1F0(*arg0, arg0, arg1, arg2);
}

