// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern u8 D_8089452C;
typedef struct { u8 p0[0x32]; s16 u32; u8 p34[0x34]; f32 u68; u8 p6c[4]; f32 u70; u8 p74[0x4A]; s16 uBE; u8 pC0[0x1F4]; u8 *u2B4; } S;
void func_800015E0(S *a) {
    a->u70 = 0.0f;
    if (a->u68 > 0.0f) {
        a->u68 = 0.0f;
    }
    a->u32 = a->uBE;
    a->u2B4 = &D_8089452C;
}
