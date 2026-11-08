// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x29C];
    /* 0x29C */ u16 unk29C;
    /* 0x29E */ u8 pad29E[0x36];
    /* 0x2D4 */ s16 unk2D4[3];
    /* 0x2DA */ u8 pad2DA[6];
    /* 0x2E0 */ s16 unk2E0;
    /* 0x2E2 */ u8 pad2E2[4];
    /* 0x2E6 */ s16 unk2E6;
} Ea;

void func_800F1D6C();
void func_80B25F0C();

void func_80000B68(Ea *this, s32 arg1, s32 arg2) {
    func_800F1D6C(this->unk2D4[this->unk2E0]);
    func_80B25F0C(this, arg1, arg2);
    this->unk2E6 = 0x14;
    this->unk29C |= 2;
}
