// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_800B8A94(s32, s32, f32, s16, f32, s32, s32);

void func_800B8B58(s32 arg0, s32 arg1, f32 arg2, s16 arg3, f32 arg4, s32 arg5) {
    func_800B8A94(arg0, arg1, arg2, arg3, arg4, 2, arg5);
}
