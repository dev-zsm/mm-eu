#include "types.h"
typedef struct { u8 p0[0x32]; s16 unk32; u8 p1[0x74 - 0x34]; f32 unk74; u8 p2[0x92 - 0x78]; s16 unk92;
  u8 p3[0x2B4 - 0x94]; void *unk2B4; u8 p4[4]; s16 unk2BC; u8 p5[0x3BD - 0x2BE]; u8 unk3BD; u8 p6[2]; u8 unk3C0; } A;
extern u8 D_80894E58[];

void func_80001EC8(A *a0) {
    a0->unk2BC = 0x190;
    a0->unk32 = a0->unk92;
    a0->unk3C0 = 12;
    a0->unk3BD |= 4;
    a0->unk2B4 = D_80894E58;
    a0->unk74 = -1.0f;
}
