// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { s16 a; s16 b; s16 c; s16 d; s32 pad8[2]; s32 e; } T;
extern T D_801BE3E0;
void Actor_GetScreenPos(s32, s32, s16 *, s16 *);
f32 OLib_Vec3fDist(s32, s32);
s32 Play_GetCamera(s32, s16);
s32 func_800F2074(s16 arg0, s32 arg1) {
    f32 temp_f0;
    s16 sp2A;
    s16 sp28;
    if ((D_801BE3E0.a == -1) || (arg0 == -1)) {
        return 4;
    }
    Actor_GetScreenPos(D_801BE3E0.e, arg1, &sp2A, &sp28);
    temp_f0 = OLib_Vec3fDist(arg1 + 0x3C, Play_GetCamera(D_801BE3E0.e, D_801BE3E0.d) + 0x5C);
    if ((sp2A >= 0x29) && (sp2A < 0x118) && (sp28 >= 0x29) && (sp28 < 0xC8) && (temp_f0 < 700.0f)) {
        return 1;
    }
    if (D_801BE3E0.b < 6) {
        return 2;
    }
    if (arg0 == D_801BE3E0.a) {
        return 0;
    }
    return 3;
}
