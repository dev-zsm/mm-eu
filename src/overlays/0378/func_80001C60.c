// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct E {
    s32 w[6];
} E;

typedef struct Pl {
    /* 0x0000 */ u8 pad0[0x1F2C];
    /* 0x1F2C */ u8 unk1F2C;
} Pl;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ u8 unk144[0x14C];
    /* 0x290 */ void *unk290;
    /* 0x294 */ u8 pad294[0x4C];
    /* 0x2E0 */ s16 unk2E0;
} Ea;

extern E D_80A882A8[];
extern u8 D_80A87490[];
void func_80A84ABC();

void func_80001C60(Ea *this, Pl *play) {
    if (play->unk1F2C == 0) {
        this->unk2E0 = 0x26;
        func_80A84ABC(this, play, &this->unk144, &D_80A882A8[this->unk2E0], 0);
        this->unk290 = D_80A87490;
    }
}
