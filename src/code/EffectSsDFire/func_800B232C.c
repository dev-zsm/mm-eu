// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u8 a[12]; u8 b[12]; u8 c[12]; s16 d[5]; s16 pad; s32 e; } L;
void Math_Vec3f_Copy();
void EffectSs_Spawn(s32, s32, s32, void *);
void EffectSsDFire_Spawn(s32 a0, s32 a1, s32 a2, s32 a3, s16 a4, s16 a5, s16 a6, s16 a7, s16 a8, s32 a9) {
    L l;
    Math_Vec3f_Copy(&l.a, a1);
    Math_Vec3f_Copy(&l.b, a2);
    Math_Vec3f_Copy(&l.c, a3);
    l.d[0] = a4;
    l.d[1] = a5;
    l.d[2] = a6;
    l.d[3] = a7;
    l.d[4] = a8;
    l.e = a9;
    EffectSs_Spawn(a0, 6, 0x80, &l);
}
