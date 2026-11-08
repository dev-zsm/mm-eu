// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void Math_Vec3f_Copy(void *, s32);

void EffectSsDtBubble_SpawnCustomColor(struct PlayState *play, struct Vec3f *pos, struct Vec3f *velocity, struct Vec3f *accel, struct Color_RGBA8 *primColor, struct Color_RGBA8 *envColor, s16 scale, s16 life, s16 randXZ) {
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

    Math_Vec3f_Copy(l.sp18, pos);
    Math_Vec3f_Copy(l.sp24, velocity);
    Math_Vec3f_Copy(l.sp30, accel);
    Color_RGBA8_Copy(l.sp3C, primColor);
    Color_RGBA8_Copy(l.sp40, envColor);
    l.sp44 = scale;
    l.sp46 = life;
    l.sp4A = randXZ;
    l.sp4C = 1;
    EffectSs_Spawn((s32)play, 0xE, 0x80, l.sp18);
}
