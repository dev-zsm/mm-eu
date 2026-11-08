// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x284];
    /* 0x284 */ void *unk284;
    /* 0x288 */ u8 pad288[0x24];
    /* 0x2AC */ u8 unk2AC;
    /* 0x2AD */ u8 pad2AD[0x13];
    /* 0x2C0 */ s16 unk2C0;
} Ea;

extern u8 D_80BE9940[];
void func_80BE984C(Ea *, s32, f32);

void func_80000210(Ea *this) {
    if (this->unk2AC == 0) {
        func_80BE984C(this, 4, 1.0f);
    } else {
        func_80BE984C(this, 0, 1.0f);
    }
    this->unk2C0 = 0;
    this->unk284 = D_80BE9940;
}
