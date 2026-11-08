// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x1B4];
    /* 0x1B4 */ s16 unk1B4;
} Ea;

void func_800B6490();
void func_800E2318();

void func_80000878(Ea *this, s32 arg1) {
    s16 v = this->unk1B4;

    if (v == 0) {
        func_800B6490(this);
        v = this->unk1B4;
    }
    if (v >= 0x1A) {
        func_800E2318(arg1, arg1 + 0x18884, (u8 *)this + 0x1DC, this);
    }
}
