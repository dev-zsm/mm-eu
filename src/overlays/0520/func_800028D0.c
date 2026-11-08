// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x316];
    /* 0x316 */ s16 unk316;
    /* 0x318 */ u8 pad318[2];
    /* 0x31A */ s16 unk31A;
    /* 0x31C */ s16 unk31C;
} Ea;

void func_800028D0(Ea *this) {
    if (this->unk316 != 0) {
        this->unk31A = this->unk316;
        return;
    }
    if (this->unk31C == 0x64) {
        if (this->unk31A == 0) {
            this->unk31C = 0;
            return;
        }
        this->unk31A -= 1;
        return;
    }
    this->unk31C += 1;
    if (this->unk31C == 0x64) {
        this->unk31A = 2;
    }
}
