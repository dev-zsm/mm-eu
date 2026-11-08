// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x5E];
    /* 0x092 */ s16 unk92;
    /* 0x094 */ u8 pad94[0x1F8];
    /* 0x28C */ s16 unk28C;
} Ea;

void func_80000154(Ea *this) {
    s16 d = this->unk92 - this->unk32;
    s32 a;

    if (d < 0) {
        a = -d;
    } else {
        a = d;
    }
    this->unk28C = 0;
    if (a < 0x4E20) {
        this->unk28C = this->unk92 - this->unk32;
        if (this->unk28C > 0x2710) {
            this->unk28C = 0x2710;
            return;
        }
        if (this->unk28C < -0x2710) {
            this->unk28C = -0x2710;
        }
    }
}
