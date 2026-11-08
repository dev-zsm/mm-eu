// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x148];
    /* 0x148 */ u8 unk148[0x44];
    /* 0x18C */ void *unk18C;
    /* 0x190 */ u8 pad190[0x20A];
    /* 0x39A */ s16 unk39A;
    /* 0x39C */ u8 pad39C[8];
    /* 0x3A4 */ s16 unk3A4;
} Ea;

extern u8 D_80A48AB8[];
extern u8 D_80A46BBC[];
void func_800B8C4C();
void func_800BD9E0();

void func_800005E8(Ea *this) {
    func_800B8C4C(this, 0x6977);
    func_800BD9E0(&this->unk148, D_80A48AB8, 1);
    this->unk39A = 1;
    this->unk3A4 = 2;
    this->unk18C = D_80A46BBC;
}
