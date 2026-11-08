// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x278];
    /* 0x278 */ void *unk278;
    /* 0x27C */ u8 pad27C[8];
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8 pad286[0xA];
    /* 0x290 */ s16 unk290;
    /* 0x292 */ u8 pad292[0xDF];
    /* 0x371 */ u8 unk371;
    /* 0x372 */ u8 pad372[0xB93];
    /* 0xF05 */ u8 unkF05;
} Ea;

extern u8 D_80A5E148[];
void func_80A5C360();

void func_80002090(Ea *this) {
    if (this->unk371 != 0) {
        func_80A5C360(this, 2);
        this->unk290 = 0x14;
    } else {
        func_80A5C360(this, 0xC);
        this->unk290 = 0x28;
    }
    this->unkF05 &= 0xFFFB;
    this->unk284 = 9;
    this->unk278 = D_80A5E148;
}
