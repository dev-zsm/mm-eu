// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void Math_Vec3f_Copy(void *, s32);

void EffectSsDeadDs_Spawn(struct PlayState *play, struct Vec3f *pos, struct Vec3f *velocity, struct Vec3f *accel, s16 scale, s16 scaleStep, s16 alpha, s32 life) {
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

    Math_Vec3f_Copy(l.p0, pos);
    Math_Vec3f_Copy(l.p1, velocity);
    Math_Vec3f_Copy(l.p2, accel);
    l.s0 = scale;
    l.s1 = scaleStep;
    l.s2 = alpha;
    l.w = life;
    EffectSs_Spawn(play, 0x22, 0x64, l.p0);
}
