// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x3C];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x4A];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0x7C];
    /* 0x13C */ void *unk13C;
    /* 0x140 */ u8 pad140[4];
    /* 0x144 */ u8 unk144[0x150];
    /* 0x294 */ void *unk294;
} Ea;

extern u8 D_80A05C44[];
extern u8 D_80A05AD4[];
extern u8 D_80A0510C[];
void func_800BD9E0();

void func_80000528(Ea *this) {
    func_800BD9E0(&this->unk144, D_80A05C44, 1);
    this->unk70 = 10.0f;
    this->unk32 = this->unkBE;
    this->unk13C = D_80A05AD4;
    this->unk294 = D_80A0510C;
}
