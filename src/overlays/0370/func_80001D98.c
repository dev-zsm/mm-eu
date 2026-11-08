// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x32];
    /* 0x32 */ s16 unk32;
    /* 0x34 */ u8 pad34[0x5E];
    /* 0x92 */ s16 unk92;
} Ea;

s32 func_80001D98(Ea *this) {
    s16 d;
    s32 a;
    s32 r;

    d = this->unk92 - this->unk32;
    if (d < 0) {
        a = -d;
    } else {
        a = d;
    }
    if ((a & 0xFFFF) < 0x1600) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
