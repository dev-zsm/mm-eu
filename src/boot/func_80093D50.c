// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_8008C380(void);
s32 func_8008C3C4(void);
s32 func_80094190(s32, s32, s32);

s32 func_80093D50(s32 arg0, s32 arg1, s32 arg2) {
    s32 ret;

    func_8008C380();
    ret = func_80094190(arg0, arg1, arg2);
    func_8008C3C4();
    return ret;
}
