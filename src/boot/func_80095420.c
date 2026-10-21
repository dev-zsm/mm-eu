// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80095420(s32 a0) {
    *(s32 *)0xA4040010 = a0;
}
