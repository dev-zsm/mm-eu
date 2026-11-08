// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x14];
    /* 0x014 */ s16 unk14;
    /* 0x016 */ u8 pad16[2];
    /* 0x018 */ s16 unk18;
    /* 0x01A */ u8 pad1A[0x12A];
    /* 0x144 */ void *unk144;
} Ea;

extern u8 D_80AAF148[];
void func_80151E7C();

void func_800004A8(Ea *this, s32 arg1) {
    if (this->unk14 > 0) {
        this->unk14 -= 1;
        return;
    }
    if (this->unk18 != 0) {
        func_80151E7C(arg1, 0x1230);
    } else {
        func_80151E7C(arg1, 0x122D);
    }
    this->unk144 = D_80AAF148;
}
