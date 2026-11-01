// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s16 x, y, z;
} Vec3s_;

extern void EffectSs_Spawn(s32, s32, s32, s32 *);
extern void Actor_PlaySfx(s32, s32, s16);

void EffectSsEnFire_SpawnVec3s(s32 arg0, s32 arg1, Vec3s_ *arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    s16 sp2E;
    s16 sp2C;
    s16 sp2A;
    s16 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    s32 sp18;

    sp1C = arg2->x;
    sp20 = arg2->y;
    sp28 = arg3;
    sp2C = arg5 | 0x8000;
    sp18 = arg1;
    sp2A = arg4;
    sp2E = arg6;
    sp24 = arg2->z;
    if (arg1 != 0) {
        Actor_PlaySfx(arg1, 0x2822, arg3);
    }
    EffectSs_Spawn(arg0, 0x1D, 0x80, &sp18);
}
