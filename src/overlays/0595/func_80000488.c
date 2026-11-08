// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x254];
    /* 0x254 */ void *unk254;
    /* 0x258 */ u8 pad258[0x20];
    /* 0x278 */ s16 unk278;
    /* 0x27A */ u8 pad27A[2];
    /* 0x27C */ s16 unk27C;
    /* 0x27E */ u8 pad27E[2];
    /* 0x280 */ s32 unk280;
    /* 0x284 */ s32 unk284;
    /* 0x288 */ s32 unk288;
    /* 0x28C */ s32 unk28C;
} Ea;

extern u8 D_80BCCD8C[];
void func_800B844C();

void func_80000488(Ea *this, s32 arg1) {
    s32 t;

    if (this->unk280 == 0) {
        this->unk27C = 0;
    }
    t = this->unk288;
    if (t != 0) {
        this->unk284 = 1;
        this->unk28C = 1;
        func_800B844C(t, arg1, t);
    }
    this->unk278 = 1;
    this->unk254 = D_80BCCD8C;
}
