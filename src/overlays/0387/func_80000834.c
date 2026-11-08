// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Pl {
    /* 0x0000 */ u8 pad0[0x1F2C];
    /* 0x1F2C */ u8 unk1F2C;
} Pl;

typedef struct Ea {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x198];
    /* 0x1A0 */ void *unk1A0;
} Ea;

extern u8 D_6002470[];
extern u8 D_80A94624[];
void func_800CABA0();
void func_800CABC4();

void func_80000834(Ea *this, Pl *play) {
    if (play->unk1F2C == 0) {
        func_800CABA0(this, 3);
        func_800CABC4(play, this, D_6002470);
        this->unk4 |= 1;
        this->unk1A0 = D_80A94624;
    }
}
