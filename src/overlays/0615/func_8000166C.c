// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x70];
    /* 0x070 */ f32 unk70;
    /* 0x074 */ u8 pad74[0x1E];
    /* 0x092 */ s16 unk92;
    /* 0x094 */ u8 pad94[0x1F0];
    /* 0x284 */ void *unk284;
    /* 0x288 */ u8 pad288[0x42];
    /* 0x2CA */ s16 unk2CA;
    /* 0x2CC */ u8 pad2CC[8];
    /* 0x2D4 */ s16 unk2D4;
    /* 0x2D6 */ s16 unk2D6;
} Ea;

extern u8 D_80BE7310[];
void func_80BE5EDC(Ea *, s32, f32);
void func_80BE6080();

void func_8000166C(Ea *this) {
    func_80BE5EDC(this, 0xF, 1.0f);
    this->unk2D4 = 0;
    this->unk70 = 0.0f;
    this->unk2D6 = this->unk92 + 0x8000;
    func_80BE6080(this);
    this->unk2CA = 6;
    this->unk284 = D_80BE7310;
}
