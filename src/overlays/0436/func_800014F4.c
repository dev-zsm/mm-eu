// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x16];
    /* 0x016 */ s16 unk16;
    /* 0x018 */ u8 pad18[0xC];
    /* 0x024 */ u8 unk24[4];
    /* 0x028 */ f32 unk28;
    /* 0x02C */ u8 pad2C[0x92];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0xB0];
    /* 0x070 */ u8 pad70dummy[0];
} Ea;

typedef struct Eb {
    /* 0x000 */ u8 pad0[0x16];
    /* 0x016 */ s16 unk16;
    /* 0x018 */ u8 pad18[0xC];
    /* 0x024 */ u8 unk24[4];
    /* 0x028 */ f32 unk28;
    /* 0x02C */ u8 pad2C[0x44];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ u8 pad78[0x46];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0x118];
    /* 0x1D8 */ u8 unk1D8[1];
} Eb;

void func_800FFCBC();
f32 func_80100248();
void func_80ACFCBC();

void func_800014F4(Eb *this, s32 arg1) {
    f32 r;

    func_800FFCBC(&this->unkBE, this->unk16, 0xA, 0x1000, 0x500);
    r = func_80100248(this->unk24, this->unk1D8, this->unk70);
    this->unk28 = this->unk28 + this->unk74;
    if (r == 0.0f) {
        func_80ACFCBC(this);
    }
}
