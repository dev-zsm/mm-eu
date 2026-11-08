// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct V {
    s32 x;
    s32 y;
    s32 z;
} V;

typedef struct Eb {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s16 unk18;
} Eb;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ V unk24;
    /* 0x030 */ u8 pad30[8];
    /* 0x038 */ s8 unk38;
    /* 0x039 */ u8 pad39[3];
    /* 0x03C */ V unk3C;
    /* 0x048 */ u8 pad48[0x18C];
    /* 0x1D4 */ void *unk1D4;
    /* 0x1D8 */ Eb *unk1D8;
    /* 0x1DC */ u8 pad1DC[0x44];
    /* 0x220 */ u16 unk220;
} Ea;

extern u8 D_80AC59B8[];
void func_80147CC4();
void func_800F1D6C();

void func_800009F8(Ea *this, s32 arg1) {
    func_80147CC4(arg1);
    this->unk1D4 = D_80AC59B8;
    this->unk220 &= 0xFFFD;
    this->unk3C = this->unk24;
    func_800F1D6C(this->unk38);
    this->unk1D8->unk18 = 0;
}
