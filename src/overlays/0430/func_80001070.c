// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x38];
    /* 0x038 */ s8 unk38;
    /* 0x039 */ u8 pad39[0x19B];
    /* 0x1D4 */ void *unk1D4;
} Ea;

extern u8 D_80AC5AA8[];
s32 func_801529DC();
s32 func_80147B34();
void func_80147CC4();
void func_800F1D6C();

void func_80001070(Ea *this, s32 arg1) {
    if (func_801529DC(arg1 + 0x4908) == 5 && func_80147B34(arg1) != 0) {
        func_80147CC4(arg1);
        this->unk1D4 = D_80AC5AA8;
        func_800F1D6C(this->unk38);
    }
}
