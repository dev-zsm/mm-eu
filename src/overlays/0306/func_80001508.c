// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x8A];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0x7C];
    /* 0x13C */ void *unk13C;
    /* 0x140 */ u8 pad140[4];
    /* 0x144 */ u8 unk144[0x154];
    /* 0x298 */ void *unk298;
    /* 0x29C */ u8 pad29C[8];
    /* 0x2A4 */ f32 unk2A4;
    /* 0x2A8 */ f32 unk2A8;
} Ea;

extern u8 D_80A0E208[];
extern u8 D_60031DC[];
extern u8 D_80A0D7C8[];
extern f32 D_80A0E4EC;
void func_80137828(u8 *, u8 *, f32);

void func_80001508(Ea *this) {
    this->unk13C = D_80A0E208;
    func_80137828(this->unk144, D_60031DC, -3.0f);
    this->unk2A8 = D_80A0E4EC;
    this->unk2A4 = 1.0f;
    this->unk32 = this->unkBE;
    this->unk298 = D_80A0D7C8;
}
