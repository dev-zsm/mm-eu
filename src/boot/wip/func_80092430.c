// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_8009E980;
extern s32 D_8009E984;

void func_80092430(s32 arg0, s32 arg1) {
    D_8009E980 = arg0;
    D_8009E984 = arg1;
}
