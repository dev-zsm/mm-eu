// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Pl {
    /* 0x00000 */ u8 pad0[0x16810];
    /* 0x16810 */ u16 unk16810;
} Pl;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x4CC];
    /* 0x4CC */ s32 unk4CC;
    /* 0x4D0 */ u8 pad4D0[4];
    /* 0x4D4 */ s32 unk4D4;
} Ea;

void func_80B5EC40();
void func_80B5DBB8();

void func_800028FC(Ea *this, Pl *play) {
    func_80B5EC40(this, play);
    func_80B5DBB8(this, play, 0);
    if (play->unk16810 == 0x33B6) {
        this->unk4CC = 1;
        this->unk4D4 = 1;
    } else {
        this->unk4CC = 0;
        this->unk4D4 = 0;
    }
}
