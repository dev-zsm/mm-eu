// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Eb {
    /* 0x0 */ u8 pad0[2];
    /* 0x2 */ u16 unk2;
} Eb;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x2B1];
    /* 0x2B1 */ u8 unk2B1;
    /* 0x2B2 */ u8 pad2B2[6];
    /* 0x2B8 */ Eb *unk2B8;
} Ea;

void func_80151DF4();

s32 func_8000090C(Ea *this, s32 arg1) {
    if ((this->unk2B1 == 0 ? 0 : --this->unk2B1) == 0) {
        func_80151DF4(arg1, this->unk2B8->unk2, 0, this);
        return 1;
    }
    return 0;
}
