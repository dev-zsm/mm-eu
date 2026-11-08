// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x60];
    /* 0x068 */ f32 unk68;
    /* 0x06C */ u8 pad6C[4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ u8 pad78[0x200];
    /* 0x278 */ void *unk278;
    /* 0x27C */ u8 pad27C[8];
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8 pad286[4];
    /* 0x28A */ s16 unk28A;
} Ea;

extern u8 D_80A5DB84[];
void func_80A5C360();
void func_800B8C4C();

void func_80001ACC(Ea *this) {
    func_80A5C360(this, 0);
    this->unk28A = 0x14;
    this->unk70 = 0.0f;
    this->unk74 = 0.0f;
    this->unk68 = 10.0f;
    func_800B8C4C(this, 0x39C3);
    this->unk4 |= 0x08000000;
    this->unk284 = 0xF;
    this->unk278 = D_80A5DB84;
}
