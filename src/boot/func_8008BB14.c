// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_800958E0(void *dst, void *src);
void func_8008B870(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);

void func_8008BB14(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 sp30[4][4];

    func_8008B870(sp30, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    func_800958E0(sp30, arg0);
}
