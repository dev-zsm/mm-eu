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
    /* 0x000 */ u8 pad0[0x2C0];
    /* 0x2C0 */ void *unk2C0;
} Ea;

extern u8 D_80BA1038[];
void func_80B9FD9C();
s32 func_800EE03C();
s32 func_800EDFA0();

void func_800016DC(Ea *this, Pl *play) {
    func_80B9FD9C(this, play);
    if (func_800EE03C(play, 0x203) != 0 && play->unk1F4C[func_800EDFA0(play, 0x203)]->unk0 == 3) {
        this->unk2C0 = D_80BA1038;
    }
}
