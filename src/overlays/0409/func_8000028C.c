// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x38];
    /* 0x038 */ s8 unk38;
    /* 0x039 */ u8 pad39[0xDD];
    /* 0x116 */ s16 unk116;
    /* 0x118 */ u8 pad118[0x2C];
    /* 0x144 */ void *unk144;
} Ea;

extern u8 D_80AAEF98[];
s32 func_800F1E2C();
void func_80112D7C();

void func_8000028C(Ea *this, s32 arg1) {
    if (func_800F1E2C() != this->unk38) {
        this->unk144 = D_80AAEF98;
        this->unk116 = 0xC02;
        func_80112D7C(arg1, 0x6A, this);
    }
}
