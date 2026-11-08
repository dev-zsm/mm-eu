// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x70];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x114];
    /* 0x188 */ void *unk188;
    /* 0x18C */ u8 unk18C;
    /* 0x18D */ u8 pad18D[5];
    /* 0x192 */ s16 unk192;
    /* 0x194 */ u8 pad194[0x1A9];
    /* 0x33D */ u8 unk33D;
} Ea;

extern u8 D_80B126B0[];
void func_800B8C4C();

void func_80001234(Ea *this) {
    this->unk18C = 0;
    this->unk192 = 0x2000;
    this->unk70 = 0.0f;
    func_800B8C4C(this, 0x3873);
    func_800B8C4C(this, 0x38EC);
    this->unk33D &= 0xFFFE;
    this->unk188 = D_80B126B0;
}
