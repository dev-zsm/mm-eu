// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
} Ea;

typedef struct Eb {
    /* 0x000 */ u8 pad0[0x2B8];
    /* 0x2B8 */ Ea *unk2B8;
} Eb;

void func_800B701C();

s32 func_80000828(Eb *this, s32 arg1) {
    if (this->unk2B8->unk1 == 2) {
        func_800B701C(arg1, 0, 7);
    }
    return 0;
}
