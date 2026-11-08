// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x83];
    /* 0x0B7 */ u8 unkB7;
    /* 0x0B8 */ u8 padB8[6];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0x1E2];
    /* 0x2A2 */ s16 unk2A2;
} Ea;

void func_80ABBD48();
void func_80ABCAD4();
void func_80ABCE78();

void func_80001228(Ea *this) {
    if (this->unk2A2 != 0) {
        this->unk2A2 -= 1;
    }
    if (this->unk2A2 == 0) {
        func_80ABBD48(this);
        if (this->unkB7 == 0) {
            func_80ABCE78(this, 0);
            return;
        }
        this->unk32 = this->unkBE;
        func_80ABCAD4(this);
    }
}
