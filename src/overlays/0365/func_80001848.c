// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x68];
    /* 0x068 */ f32 unk68;
    /* 0x06C */ u8 pad6C[4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x204];
    /* 0x278 */ void *unk278;
    /* 0x27C */ u8 pad27C[8];
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8 pad286[4];
    /* 0x28A */ s16 unk28A;
    /* 0x28C */ u8 pad28C[0xC79];
    /* 0xF05 */ u8 unkF05;
} Ea;

extern u8 D_80A5D8FC[];
void func_800B8C4C();

void func_80001848(Ea *this) {
    this->unk28A = 0x28;
    this->unkF05 |= 4;
    this->unk70 = 15.0f;
    this->unk68 = 13.0f;
    func_800B8C4C(this, 0x3812);
    func_800B8C4C(this, 0x39BE);
    this->unk284 = 6;
    this->unk278 = D_80A5D8FC;
}
