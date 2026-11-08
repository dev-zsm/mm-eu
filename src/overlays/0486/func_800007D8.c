// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x188];
    /* 0x188 */ void *unk188;
    /* 0x18C */ u8 pad18C[0x42];
    /* 0x1CE */ u16 unk1CE;
} Ea;

extern u8 D_80B23CC0[];
s32 func_800B8254();
void func_8013B284();

s32 func_800007D8(Ea *this) {
    s32 r = 0;

    if (this->unk1CE & 7) {
        if (func_800B8254(this) != 0) {
            func_8013B284(&this->unk1CE, 0, 7);
            r = 1;
            this->unk188 = D_80B23CC0;
        }
    }
    return r;
}
