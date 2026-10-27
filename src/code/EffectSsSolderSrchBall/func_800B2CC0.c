// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSs_Spawn(s32, s32, s32, void *);
void Math_Vec3f_Copy(void *, s32);

typedef struct {
    s32 a[3];
    s32 b[3];
    s32 c[3];
    s16 d;
    s32 e;
    s16 f;
} SolderSrchParams;

void EffectSsSolderSrchBall_Spawn(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s32 arg5, s16 arg6) {
    SolderSrchParams sp;

    Math_Vec3f_Copy(sp.a, arg1);
    Math_Vec3f_Copy(sp.b, arg2);
    Math_Vec3f_Copy(sp.c, arg3);
    sp.d = arg4;
    sp.e = arg5;
    sp.f = arg6;
    EffectSs_Spawn(arg0, 0x18, 0x80, &sp);
}
