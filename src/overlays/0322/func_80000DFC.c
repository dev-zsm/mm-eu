// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ob {
    /* 0x0 */ u16 unk0;
} Ob;

typedef struct Pl {
    /* 0x0000 */ u8 pad0[0x1F4C];
    /* 0x1F4C */ Ob *unk1F4C[1];
} Pl;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ s16 unk144;
    /* 0x146 */ u8 pad146[6];
    /* 0x14C */ void *unk14C;
} Ea;

extern u8 D_80A1F1D4[];
s32 func_800EE03C();
s32 func_800EDFA0();

void func_80000DFC(Ea *this, Pl *play) {
    u16 v;

    if (func_800EE03C(play, 0x64) != 0) {
        v = play->unk1F4C[func_800EDFA0(play, 0x64)]->unk0;
        if (v == 3) {
            this->unk14C = D_80A1F1D4;
            this->unk144 = 0x5A;
        }
    }
}
