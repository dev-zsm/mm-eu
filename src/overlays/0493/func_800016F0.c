// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x30];
    /* 0x030 */ s16 unk30;
    /* 0x032 */ s16 unk32;
    /* 0x034 */ s16 unk34;
    /* 0x036 */ u8 pad36[0x5C];
    /* 0x092 */ s16 unk92;
    /* 0x094 */ u8 pad94[0x28];
    /* 0x0BC */ s16 unkBC;
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ s16 unkC0;
    /* 0x0C2 */ u8 padC2[0x82];
    /* 0x144 */ void *unk144;
} Ea;

extern u8 D_80B41760[];
void func_800B8C4C();

void func_800016F0(Ea *this, s32 arg1) {
    this->unkBC = 0;
    this->unkC0 = 0;
    this->unkBE = this->unk92;
    this->unk30 = this->unk30;
    this->unk32 = this->unk32;
    this->unk34 = this->unk34;
    func_800B8C4C(this, 0x294B);
    this->unk144 = D_80B41760;
}
