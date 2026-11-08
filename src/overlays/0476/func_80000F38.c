// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x3C];
    /* 0x070 */ f32 unk70[3];
    /* 0x07C */ u8 pad7C[0x42];
    /* 0x0BE */ s16 unkBE;
    /* 0x0C0 */ u8 padC0[0x84];
    /* 0x144 */ u8 unk144[0x4A];
    /* 0x18E */ s16 unk18E;
} Ea;

s32 func_80137070();
void func_800FEE3C(f32 *, f32, f32);
void func_80B11890();

void func_80000F38(Ea *this, s32 arg1) {
    if (func_80137070(this->unk144) != 0) {
        this->unk32 = this->unkBE;
        func_80B11890(this);
        this->unk18E = 0x17;
        return;
    }
    func_800FEE3C(this->unk70, 0.0f, 0.5f);
    this->unkBE += 0x1000;
}
