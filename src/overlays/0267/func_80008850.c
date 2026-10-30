// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern u8 D_8099F6B8;
typedef struct { u8 p[0x12F4]; s16 u12F4; } G;
extern G *D_801EB7E0;
typedef struct { u8 p0[0x148]; u8 u148; u8 p149; s16 u14A; u8 p14C[2]; s16 u14E; u8 p150[0x2D0]; u8 *u420; } S;
void func_80008850(S *a, s32 b) {
    a->u420 = &D_8099F6B8; a->u148 = 0; a->u14A = D_801EB7E0->u12F4 + 60; a->u14E = 250;
}
