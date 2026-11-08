// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct S {
    /* 0x00 */ u8 pad0[0x2C];
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ u8 pad2E[2];
    /* 0x30 */ f32 unk30;
} S;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x70];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0xD0];
    /* 0x144 */ u8 unk144[0x1A0];
    /* 0x2E4 */ u8 pad2E4[8];
    /* 0x2EC */ void *unk2EC;
    /* 0x2F0 */ u8 pad2F0[0x34];
    /* 0x324 */ S unk324;
    /* 0x358 */ u8 pad358[0x18];
    /* 0x370 */ s16 unk370;
} Ea;

extern u8 D_6009E58[];
extern u8 D_80B2DB7C[];
extern f32 D_80B33C28;
void func_80137934(u8 *, u8 *, f32);

void func_80005434(Ea *this) {
    S *v;

    this->unk70 = 0.0f;
    v = &this->unk324;
    func_80137934(this->unk144, D_6009E58, -10.0f);
    this->unk370 = 0;
    v->unk30 = D_80B33C28;
    v->unk2C = 0x4B0;
    this->unk2EC = D_80B2DB7C;
}
