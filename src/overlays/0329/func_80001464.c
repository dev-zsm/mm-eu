// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Pl {
    /* 0x00000 */ u8 pad0[0x170E7];
    /* 0x170E7 */ u8 unk170E7;
    /* 0x170E8 */ u8 pad170E8[0xE];
    /* 0x170F6 */ u8 unk170F6;
    /* 0x170F7 */ u8 pad170F7;
    /* 0x170F8 */ u8 unk170F8;
} Pl;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x14C];
    /* 0x14C */ u8 unk14C;
} Ea;

extern u8 D_801BE700;
extern u16 D_801E6EFC;

void func_80001464(Ea *this, Pl *play) {
    if ((D_801E6EFC >= 0xBAAA && D_801E6EFC < 0xF555 && play->unk170F6 != 0) || play->unk170F8 != 0) {
        D_801BE700 = 0;
        play->unk170E7 = 2;
    }
    if (D_801BE700 == 0) {
        this->unk14C = 0;
    }
}
