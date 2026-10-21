// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80090650(f32 *, f32, f32, f32, f32);
void func_800958E0(f32 *, s32);

void func_800907D4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp20[16];

    func_80090650(sp20, arg1, arg2, arg3, arg4);
    func_800958E0(sp20, arg0);
}
