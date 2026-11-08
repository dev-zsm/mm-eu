// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Eb {
    /* 0x000 */ u8 pad0[0xA6C];
    /* 0xA6C */ s32 unkA6C;
} Eb;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0xD90];
    /* 0xD90 */ Eb *unkD90;
} Ea;

void func_800BBED8();

void func_800008D0(Ea *this, s32 arg1) {
    func_800BBED8(arg1, arg1 + 0x1CA0, this->unkD90, 2);
    func_800BBED8(arg1, arg1 + 0x1CA0, this, 4);
    this->unkD90->unkA6C &= ~0x20;
}
