// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 func_8008FBA0(void);
extern s32 func_8008A6E0(s32 a0);

s32 func_8008AE80(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_8008FBA0() != 0) {
        return -1;
    }
    *(s32 *)0xA4040000 = arg1;
    *(s32 *)0xA4040004 = func_8008A6E0(arg2);
    if (arg0 == 0) {
        *(s32 *)0xA404000C = arg3 - 1;
    } else {
        *(s32 *)0xA4040008 = arg3 - 1;
    }
    return 0;
}
