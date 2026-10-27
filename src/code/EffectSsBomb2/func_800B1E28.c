// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void Math_Vec3f_Copy(void *, s32);
extern void EffectSs_Spawn(s32, s32, s32, void *);

void EffectSsBomb2_SpawnFade(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct {
        s32 v0[3];
        s32 v1[3];
        s32 v2[3];
        s16 s0;
        s16 s1;
        s8 b0;
    } sp;

    Math_Vec3f_Copy(sp.v0, arg1);
    Math_Vec3f_Copy(sp.v1, arg2);
    Math_Vec3f_Copy(sp.v2, arg3);
    sp.s0 = 100;
    sp.s1 = 0;
    sp.b0 = 0;
    EffectSs_Spawn(arg0, 3, 10, &sp);
}
