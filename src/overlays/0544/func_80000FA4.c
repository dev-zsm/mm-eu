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
    /* 0x000 */ u8 pad0[0x29C];
    /* 0x29C */ void *unk29C;
} Ea;

extern u8 D_80B94BD4[];
void func_80B94180();
s32 func_800EE03C();
s32 func_800EDFA0();

void func_80000FA4(Ea *this, Pl *play) {
    func_80B94180(this);
    if (func_800EE03C(play, 0x203) != 0 && play->unk1F4C[func_800EDFA0(play, 0x203)]->unk0 == 4) {
        this->unk29C = D_80B94BD4;
    }
}
