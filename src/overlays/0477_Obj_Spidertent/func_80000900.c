// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x3A4];
    /* 0x3A4 */ u8 unk3A4[0xC];
    /* 0x3B0 */ f32 unk3B0;
    /* 0x3B4 */ f32 unk3B4;
    /* 0x3B8 */ f32 unk3B8;
    /* 0x3BC */ f32 unk3BC;
    /* 0x3C0 */ u8 unk3C0;
    /* 0x3C1 */ u8 pad3C1;
    /* 0x3C2 */ u8 unk3C2;
    /* 0x3C3 */ u8 unk3C3;
    /* 0x3C4 */ u8 unk3C4;
    /* 0x3C5 */ u8 unk3C5;
} Ea;

extern f32 D_80B160D0;
extern f32 D_80B160E8;
extern f32 D_80B16100;
extern f32 D_80B16118;
void func_800FF30C();

void func_80000900(Ea *this, s32 arg1) {
    func_800FF30C(this->unk3A4, arg1);
    this->unk3C2 = 0xFF;
    this->unk3C3 = 0xFF;
    this->unk3C4 = 0xFF;
    this->unk3C5 = 0xFF;
    this->unk3B0 = D_80B160D0;
    this->unk3B4 = D_80B160E8;
    this->unk3B8 = D_80B16100;
    this->unk3BC = D_80B16118;
    this->unk3C0 = 0;
}
