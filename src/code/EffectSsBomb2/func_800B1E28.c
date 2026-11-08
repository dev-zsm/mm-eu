// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern void Math_Vec3f_Copy(void *, s32);

void EffectSsBomb2_SpawnFade(struct PlayState *play, struct Vec3f *pos, struct Vec3f *velocity, struct Vec3f *accel) {
    struct {
        s32 v0[3];
        s32 v1[3];
        s32 v2[3];
        s16 s0;
        s16 s1;
        s8 b0;
    } sp;

    Math_Vec3f_Copy(sp.v0, pos);
    Math_Vec3f_Copy(sp.v1, velocity);
    Math_Vec3f_Copy(sp.v2, accel);
    sp.s0 = 100;
    sp.s1 = 0;
    sp.b0 = 0;
    EffectSs_Spawn(play, 3, 10, &sp);
}
