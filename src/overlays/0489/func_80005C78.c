// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x68];
    /* 0x068 */ f32 unk68;
    /* 0x06C */ u8 pad6C[0x280];
    /* 0x2EC */ void *unk2EC;
    /* 0x2F0 */ u8 pad2F0[0xB0];
    /* 0x3A0 */ f32 unk3A0;
    /* 0x3A4 */ f32 unk3A4;
    /* 0x3A8 */ u8 pad3A8[2];
    /* 0x3AA */ s16 unk3AA;
} Ea;

extern u8 D_80B2E3A0[];
extern f32 D_80B33C68;
extern f32 D_80B33C6C;
extern f32 D_80B33C70;

void func_80005C78(Ea *this) {
    this->unk3A0 = D_80B33C68;
    this->unk3A4 = D_80B33C6C;
    this->unk3AA = 0xBB8;
    this->unk68 = this->unk68 * D_80B33C70;
    this->unk2EC = D_80B2E3A0;
}
