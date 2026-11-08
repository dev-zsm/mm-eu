// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x3C];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x4A];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0xC8];
    /* 0x188 */ void *unk188;
    /* 0x18C */ u8 unk18C;
    /* 0x18D */ u8 pad18D[5];
    /* 0x192 */ s16 unk192;
    /* 0x194 */ u8 pad194[0x1A9];
    /* 0x33D */ u8 unk33D;
} Ea;

extern u8 D_80B12504[];
void func_800B8C4C();

void func_8000107C(Ea *this) {
    this->unk18C = 0x20;
    this->unk192 = 0x2000;
    this->unk70 = 0.0f;
    this->unk32 = this->unkBE;
    func_800B8C4C(this, 0x3874);
    func_800B8C4C(this, 0x38EC);
    this->unk33D &= 0xFFFE;
    this->unk188 = D_80B12504;
}
