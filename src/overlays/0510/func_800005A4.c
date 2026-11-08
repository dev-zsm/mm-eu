// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x134];
    /* 0x13C */ void *unk13C;
    /* 0x140 */ u8 pad140[0x20];
    /* 0x160 */ f32 unk160;
    /* 0x164 */ u8 pad164[0x148];
    /* 0x2AC */ void *unk2AC;
    /* 0x2B0 */ u8 pad2B0[0x48];
    /* 0x2F8 */ f32 unk2F8;
} Ea;

extern u8 D_80B63144[];
extern u8 D_80B61BB4[];
void func_800B8C4C();

void func_800005A4(Ea *this) {
    this->unk13C = D_80B63144;
    this->unk2F8 = 300.0f;
    this->unk160 = 2.0f;
    func_800B8C4C(this, 0x3986);
    this->unk4 |= 1;
    this->unk2AC = D_80B61BB4;
}
