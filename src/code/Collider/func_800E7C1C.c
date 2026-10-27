// FLAGS: -O2 -g3 -mips2
#include "types.h"
void Collider_SetQuadMidpoints(s32);
void Math_Vec3f_Copy(s32, s32);
void func_800E7C1C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 sp1C;
    s32 pad; // pad: shifts sp1C to its ROM stack slot

    Math_Vec3f_Copy(arg0 + 0x58, arg3);
    Math_Vec3f_Copy(arg0 + 0x64, arg4);
    sp1C = arg0 + 0x40;
    Math_Vec3f_Copy(sp1C, arg1);
    Math_Vec3f_Copy(arg0 + 0x4C, arg2);
    Collider_SetQuadMidpoints(sp1C);
}
