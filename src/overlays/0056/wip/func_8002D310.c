// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_8082D350(void);

void func_8002D310(s32 a, s32 b, s32 c) {
    if (c != 1 && c != 7 && c != 0x14 && c != 6) {
        func_8082D350();
    }
}
