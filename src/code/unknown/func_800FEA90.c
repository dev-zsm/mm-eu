// FLAGS: -O2 -g3 -mips2
#include "types.h"
void func_80091460(s32, s32, s32, s32);
s32 func_800FEA90(s32 arg0, s32 arg1, s32 arg2) {
    func_80091460(arg1, arg0, arg2, arg1);
    return arg0;
}
