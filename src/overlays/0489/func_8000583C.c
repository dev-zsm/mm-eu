#include "types.h"

typedef struct {
    u8 pad0[0x74];
    f32 unk74;
    u8 pad78[0x2EC - 0x78];
    void *unk2EC;
    u8 pad2F0[0x39C - 0x2F0];
    f32 unk39C;
    f32 unk3A0;
    f32 unk3A4;
    u8 pad3A8[2];
    s16 unk3AA;
} A;

extern u8 D_80B2DF58[];

void func_8000583C(A *a) {
    a->unk39C = 0.0f;
    a->unk3A4 = 0.0f;
    a->unk3AA = 0;
    a->unk74 = -15.0f;
    a->unk3A0 = 1.0f;
    a->unk2EC = D_80B2DF58;
}
