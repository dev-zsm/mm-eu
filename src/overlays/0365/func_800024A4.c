// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x34];
    /* 0x068 */ f32 unk68;
    /* 0x06C */ u8 pad6C[4];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x204];
    /* 0x278 */ void *unk278;
    /* 0x27C */ u8 pad27C[8];
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8 pad286[0xEA];
    /* 0x370 */ u8 unk370;
} Ea;

extern u8 D_80A5E548[];
void func_80A5C360();

void func_800024A4(Ea *this) {
    func_80A5C360(this, 3);
    this->unk32 = -this->unk32;
    this->unk370 = 0;
    this->unk284 = 0xC;
    this->unk278 = D_80A5E548;
    this->unk70 = 7.0f;
    this->unk68 = 20.0f;
}
