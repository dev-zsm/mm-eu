// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80085DE4(s32 a0, u8 a1);

void func_80085FFC(s32 arg0, u8 *arg1) {
    while (*arg1 != 0) {
        func_80085DE4(arg0, *arg1++);
    }
}
