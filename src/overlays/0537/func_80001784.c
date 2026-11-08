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
    /* 0x000 */ u8 pad0[0x314];
    /* 0x314 */ void *unk314;
} Ea;

extern u8 D_80B859B4[];
void func_80B8460C();
s32 func_800EE03C();
s32 func_800EDFA0();

void func_80001784(Ea *this, Pl *play) {
    func_80B8460C(this);
    if (func_800EE03C(play, 0x203) != 0 && play->unk1F4C[func_800EDFA0(play, 0x203)]->unk0 == 2) {
        this->unk314 = D_80B859B4;
    }
}
