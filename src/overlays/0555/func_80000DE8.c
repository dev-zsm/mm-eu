// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x262];
    /* 0x262 */ u16 unk262;
} Ea;

s32 func_80BA4B50();
void func_8013B284();
void func_80BA4C2C();

s32 func_80000DE8(Ea *this, s32 arg1, s32 arg2) {
    s32 r = 0;

    if (func_80BA4B50(this, arg1, 4, 0x202) != 0) {
        func_8013B284(&this->unk262, 3, 7);
        this->unk262 |= 0x20;
        func_80BA4C2C(this, 0);
        r = 1;
    }
    return r;
}
