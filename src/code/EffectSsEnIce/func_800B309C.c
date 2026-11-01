// FLAGS: -O2 -g3 -mips2
#include "types.h"
void func_800B3064(s32, s32, void *, s32);
void Math_Vec3s_ToVec3f(void *, s32);
void func_800B309C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 pad;
    s32 sp1C[2];

    Math_Vec3s_ToVec3f(sp1C, arg2);
    func_800B3064(arg0, arg1, sp1C, arg3);
}
