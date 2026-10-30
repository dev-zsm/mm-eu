#include "types.h"

typedef struct { u8 p0[0x70]; f32 u70; u8 p1[0xD0]; void *u144; u8 p2[2]; s16 u14A; u8 p3[4]; f32 u150; u8 p4[0x1C]; u8 u170; } A;
extern u8 D_80968F88[];
extern f32 D_8096A5AC;

void func_8000091C(A *a) {
    a->u170 &= 0xFFFE;
    a->u14A = 0x50;
    a->u70 = 0.0f;
    a->u150 = D_8096A5AC;
    a->u144 = D_80968F88;
}
