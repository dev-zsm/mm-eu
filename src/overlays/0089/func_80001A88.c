// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80182BE0();
void func_800E7D4C();

void func_80001A88(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    if (arg1 == 2) {
        func_80182BE0(arg4 + 0x3C);
        func_800E7D4C(arg1, arg4 + 0x2A4);
    }
}
