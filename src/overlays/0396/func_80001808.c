// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x38];
    /* 0x38 */ s8 unk38;
} Ea;

s32 func_800F1984();
void func_800F1B24();
void func_80AA424C();
s32 func_800F1E2C();
void func_800F1D6C();
void func_800F1944();

void func_80001808(Ea *this, s32 arg1) {
    s16 id = this->unk38;

    if (func_800F1984(this->unk38) != 0) {
        func_800F1B24(id, this);
        func_80AA424C(this);
    } else {
        if (func_800F1E2C() == 0x7C) {
            func_800F1D6C(0x7C);
        }
        func_800F1944(id);
    }
}
