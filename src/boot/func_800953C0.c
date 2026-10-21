// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 func_8008FBD0(void);

s32 func_800953C0(s32 a0, s32 a1) {
    if (func_8008FBD0() != 0) {
        return -1;
    }
    *(s32 *)((u32)a0 | 0xA0000000) = a1;
    return 0;
}
