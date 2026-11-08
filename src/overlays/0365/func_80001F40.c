// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x70];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x204];
    /* 0x278 */ void *unk278;
    /* 0x27C */ u8 pad27C[8];
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8 pad286[8];
    /* 0x28E */ s16 unk28E;
    /* 0x290 */ u8 pad290[0xD8];
    /* 0x368 */ u8 unk368;
    /* 0x369 */ u8 pad369[8];
    /* 0x371 */ u8 unk371;
} Ea;

extern u8 D_80A5DFE4[];
void func_80A5C360();
void func_800B8C4C();

void func_80001F40(Ea *this) {
    func_80A5C360(this, 0xE);
    this->unk371 = 0;
    func_800B8C4C(this, 0x1818);
    this->unk368 = 0;
    this->unk28E = 0xF;
    this->unk284 = 8;
    this->unk278 = D_80A5DFE4;
    this->unk70 = 12.0f;
}
