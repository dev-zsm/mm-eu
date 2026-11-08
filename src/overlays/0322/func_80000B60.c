// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ s16 unk144;
    /* 0x146 */ u8 pad146[4];
    /* 0x14A */ u16 unk14A;
    /* 0x14C */ void *unk14C;
} Ea;

extern u8 D_80A1EE44[];
void func_80A1ED94();
void func_800B8D94();

void func_80000B60(Ea *this, s32 arg1) {
    if (this->unk144 == 0) {
        this->unk14C = D_80A1EE44;
        func_80A1ED94(arg1);
        this->unk144 = 0x1E;
    }
    if (this->unk14A & 1) {
        func_800B8D94(this, 0x2188);
    }
}
