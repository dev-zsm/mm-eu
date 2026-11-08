// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x70];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0xD0];
    /* 0x144 */ u8 unk144[0x150];
    /* 0x294 */ void *unk294;
    /* 0x298 */ u8 pad298[2];
    /* 0x29A */ s16 unk29A;
} Ea;

extern u8 D_80A05C44[];
extern u8 D_80A05530[];
void func_800B8C4C();
void func_800BD9E0();

void func_8000094C(Ea *this) {
    this->unk29A = 0x28;
    this->unk70 = 0.0f;
    func_800B8C4C(this, 0x383C);
    func_800BD9E0(&this->unk144, D_80A05C44, 5);
    this->unk294 = D_80A05530;
}
