// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSs_Spawn(s32, s32, s32, void *);
void Math_Vec3f_Copy(void *, s32);
void Color_RGBA8_Copy(void *, s32);

void EffectSsDtBubble_SpawnCustomColor(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s16 arg8) {
    struct {
        u8 sp18[12];
        u8 sp24[12];
        u8 sp30[12];
        u8 sp3C[4];
        u8 sp40[4];
        s16 sp44;
        s16 sp46;
        s16 pad48;
        s16 sp4A;
        u8 sp4C;
    } l;

    Math_Vec3f_Copy(l.sp18, arg1);
    Math_Vec3f_Copy(l.sp24, arg2);
    Math_Vec3f_Copy(l.sp30, arg3);
    Color_RGBA8_Copy(l.sp3C, arg4);
    Color_RGBA8_Copy(l.sp40, arg5);
    l.sp44 = arg6;
    l.sp46 = arg7;
    l.sp4A = arg8;
    l.sp4C = 1;
    EffectSs_Spawn((s32)arg0, 0xE, 0x80, l.sp18);
}
