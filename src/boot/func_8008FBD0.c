// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 func_8008FBD0(void) {
    s32 v;

    v = *(s32 *)0xA4800018;
    if (v & 3) {
        return 1;
    }
    return 0;
}
