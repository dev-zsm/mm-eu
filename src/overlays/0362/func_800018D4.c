// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x148];
    /* 0x148 */ u8 unk148[0x10];
    /* 0x158 */ s32 unk158;
    /* 0x15C */ u8 pad15C[0x2F2];
    /* 0x44E */ u8 unk44E;
} Ea;

s32 func_80137C58();
void func_80A5787C();

void func_800018D4(Ea *this, s32 arg1) {
    if (func_80137C58(&this->unk148, this->unk158) != 0) {
        this->unk44E = 0;
        func_80A5787C(this, arg1);
    }
}
