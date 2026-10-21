// FLAGS: -O2 -g0 -mips2
#include "types.h"

void func_80091A40(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void func_800958E0(f32 *arg0, s32 arg1);

void func_80091B94(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp28[16];

    func_80091A40(sp28, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    func_800958E0(sp28, arg0);
}
