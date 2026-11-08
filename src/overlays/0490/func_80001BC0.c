// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0xEC];
    /* 0x0EC */ u8 unkEC[0xF8];
    /* 0x1E4 */ u16 unk1E4;
} Ea;

extern u8 D_801E7DFE;
void func_801A560C();

void func_80001BC0(Ea *this, s32 arg1) {
    if (!(D_801E7DFE & 4)) {
        if (this->unk1E4 & 2) { func_801A560C(this->unkEC, 0x30EA, this); } else { this->unk1E4 |= 2; }
    }
}
