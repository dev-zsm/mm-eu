// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x3C];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x1E];
    /* 0x092 */ s16 unk92;
    /* 0x094 */ u8 pad94[0xFC];
    /* 0x190 */ u8 unk190[0x44];
    /* 0x1D4 */ void *unk1D4;
    /* 0x1D8 */ u8 pad1D8[0x212];
    /* 0x3EA */ s16 unk3EA;
    /* 0x3EC */ u8 pad3EC[2];
    /* 0x3EE */ s16 unk3EE;
} Ea;

extern u8 D_80AE5F30[];
extern u8 D_80AE449C[];
void func_800BD9E0();
void func_800B8C4C();

void func_80000E60(Ea *this) {
    func_800BD9E0(this->unk190, D_80AE5F30, 7);
    func_800B8C4C(this, 0x38E6);
    this->unk3EA = 0;
    this->unk3EE = 0;
    this->unk32 = this->unk92;
    this->unk1D4 = D_80AE449C;
    this->unk70 = -2.0f;
}
