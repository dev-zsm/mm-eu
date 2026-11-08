// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x340];
    /* 0x340 */ u16 unk340;
} Ea;

s32 func_80BA6880();
void func_8013B284();
void func_80BA66CC();
void func_80BA7C44();

s32 func_800006C8(Ea *this, s32 arg1, s32 arg2) {
    s32 r = 0;

    if (func_80BA6880(this, arg1) != 0) {
        func_8013B284(&this->unk340, 3, 7);
        this->unk340 |= 0x10;
        func_80BA66CC(this, 5);
        func_80BA7C44(this);
        r = 1;
    }
    return r;
}
