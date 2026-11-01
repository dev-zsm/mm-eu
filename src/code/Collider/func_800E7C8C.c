// FLAGS: -O2 -g3 -mips2
#include "types.h"
void Math_Vec3f_Copy(u8 *, s32);
void func_8017C908(s32, s32, s32, f32 *, f32 *, f32 *, f32 *);
void func_800E7C8C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {




    u8 *temp_s0;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;

    temp_s0 = *(u8 **)(arg0 + 0x1C) + arg1 * 0x5C;
    Math_Vec3f_Copy(temp_s0 + 0x28, arg2);
    Math_Vec3f_Copy(temp_s0 + 0x34, arg3);
    Math_Vec3f_Copy(temp_s0 + 0x40, arg4);
    func_8017C908(arg2, arg3, arg4, &sp40, &sp3C, &sp38, &sp34);
    *(f32 *)(temp_s0 + 0x4C) = sp40;
    *(f32 *)(temp_s0 + 0x50) = sp3C;
    *(f32 *)(temp_s0 + 0x54) = sp38;
    *(f32 *)(temp_s0 + 0x58) = sp34;
}
