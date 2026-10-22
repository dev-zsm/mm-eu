// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Math_Vec3f_Copy(void *, s32);
void EffectSs_Spawn(s32, s32, s32, void *);

void EffectSsDeadDs_Spawn(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7) {
    struct {
        f32 p0[3];
        f32 p1[3];
        f32 p2[3];
        s16 s0;
        s16 s1;
        s16 s2;
        s16 pad;
        s32 w;
    } l;

    Math_Vec3f_Copy(l.p0, arg1);
    Math_Vec3f_Copy(l.p1, arg2);
    Math_Vec3f_Copy(l.p2, arg3);
    l.s0 = arg4;
    l.s1 = arg5;
    l.s2 = arg6;
    l.w = arg7;
    EffectSs_Spawn(arg0, 0x22, 0x64, l.p0);
}
