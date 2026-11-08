// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Pl {
    /* 0x0000 */ u8 pad0[0x1F34];
    /* 0x1F34 */ u16 unk1F34;
} Pl;

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s16 unk1C;
} Ea;

void func_800B8C4C();

void func_80000858(Ea *this, Pl *play) {
    if (this->unk1C == 0) {
        if (play->unk1F34 != 0x82) {
            if (play->unk1F34 == 0xE9 || play->unk1F34 == 0x19F || play->unk1F34 == 0x251) {
                func_800B8C4C(this, 0x281B);
            }
        } else {
            func_800B8C4C(this, 0x285F);
        }
    }
}
