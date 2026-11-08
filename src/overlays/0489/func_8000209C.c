// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Rec {
    /* 0x0 */ s8 *unk0;
    /* 0x4 */ s8 unk4;
} Rec;

typedef struct Mid {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ Rec *unk4;
} Mid;

typedef struct Ea {
    /* 0x0 */ u8 pad0[8];
    /* 0x8 */ Mid *unk8;
    /* 0xC */ u8 padC[2];
    /* 0xE */ s8 unkE;
    /* 0xF */ s8 unkF;
} Ea;

void func_8000209C(Ea *this, s32 arg1) {
    Mid *m = this->unk8;
    Rec *r = m->unk4;
    s8 i = this->unkE;

    if (i < r->unk4 - 1) {
        this->unkE = i + 1;
        this->unkF = r->unk0[this->unkE];
    }
}
