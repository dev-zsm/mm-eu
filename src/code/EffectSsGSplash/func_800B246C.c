#include "types.h"
typedef struct { u8 r, g, b, a; } C;
typedef struct { u8 a[12]; s8 b; u8 c; s16 d; C e; C f; } L;
void Math_Vec3f_Copy();
void EffectSs_Spawn(s32, s32, s32, void *);
void EffectSsGSplash_Spawn(s32 a0, s32 a1, C *a2, C *a3, s16 a4, s16 a5) {
    L l;
    Math_Vec3f_Copy(&l, a1);
    l.b = a4;
    l.d = a5;
    if (a2 != NULL) {
        l.e = *a2;
        l.f = *a3;
        l.c = 1;
    } else {
        l.c = 0;
    }
    EffectSs_Spawn(a0, 0xA, 0x80, &l);
}
