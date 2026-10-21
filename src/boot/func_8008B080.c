// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_8008FBD0(void);

s32 func_8008B080(u32 arg0, s32 *arg1) {
    if (func_8008FBD0() != 0) {
        return -1;
    }
    *arg1 = *(s32 *)(arg0 | 0xA0000000);
    return 0;
}
