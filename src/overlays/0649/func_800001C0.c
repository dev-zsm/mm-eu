// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x13C];
    /* 0x13C */ s32 unk13C;
    /* 0x140 */ u8 pad140[4];
    /* 0x144 */ u8 unk144[0x44];
    /* 0x188 */ void (*unk188)(struct Ea *, s32);
} Ea;

void func_80137070();
void func_80C03030();

void func_800001C0(Ea *this, s32 arg1) {
    this->unk188(this, arg1);
    if (this->unk13C != 0) {
        func_80137070(&this->unk144);
        func_80C03030(this, arg1);
    }
}
