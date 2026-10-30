#include "types.h"
typedef struct { u8 p0[0x1C]; s16 unk1C; u8 p1[0x28 - 0x1E]; f32 unk28; u8 p2[0xCC - 0x2C]; f32 unkCC; u8 p3[0x144 - 0xD0]; void *unk144; s32 unk148; } A;
extern u8 D_80B07230[];

void func_800009C0(A *a0) {
    a0->unk1C = 3;
    a0->unk148 = 10;
    a0->unkCC = 0.0f;
    a0->unk28 += 4.0f;
    a0->unk144 = D_80B07230;
}
