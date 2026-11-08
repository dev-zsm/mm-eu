// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void Math_Vec3f_Copy(void *, s32);

typedef struct {
    s32 a[3];
    s32 b[3];
    s32 c[3];
    s16 d;
    s32 e;
    s16 f;
} SolderSrchParams;

void EffectSsSolderSrchBall_Spawn(struct PlayState *play, struct Vec3f *pos, struct Vec3f *velocity, struct Vec3f *accel, s16 scale, s16 *playerDetected, s16 flags) {
    SolderSrchParams sp;

    Math_Vec3f_Copy(sp.a, pos);
    Math_Vec3f_Copy(sp.b, velocity);
    Math_Vec3f_Copy(sp.c, accel);
    sp.d = scale;
    sp.e = playerDetected;
    sp.f = flags;
    EffectSs_Spawn(play, 0x18, 0x80, &sp);
}
