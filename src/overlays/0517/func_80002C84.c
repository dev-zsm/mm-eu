// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x3C];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x1E];
    /* 0x092 */ s16 unk92;
    /* 0x094 */ u8 pad94[0x2A];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0x1EC];
    /* 0x2AC */ void *unk2AC;
    /* 0x2B0 */ s16 unk2B0;
    /* 0x2B2 */ s16 unk2B2;
} Ea;

extern u8 D_80B6CF98[];
void func_80B6AB38();
void func_800B8C4C();

void func_80002C84(Ea *this) {
    s16 v;

    func_80B6AB38(this, 8);
    v = this->unk92;
    this->unk2B2 = 0;
    this->unk70 = 10.0f;
    this->unkBE = v;
    this->unk32 = v;
    func_800B8C4C(this, 0x386C);
    this->unk2B0 = 5;
    this->unk2AC = D_80B6CF98;
}
