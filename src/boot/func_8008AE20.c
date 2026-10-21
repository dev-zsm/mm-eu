// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_8008ABF0(f32 *mf, void *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
extern void func_800958E0(f32 *mf, s32 arg1);

void func_8008AE20(s32 arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 mf[4][4];

    func_8008ABF0(&mf[0][0], arg1, arg2, arg3, arg4, arg5, arg6);
    func_800958E0(&mf[0][0], arg0);
}
