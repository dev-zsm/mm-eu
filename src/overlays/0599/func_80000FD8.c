// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x23C];
    /* 0x23C */ void *unk23C;
    /* 0x240 */ u8 pad240[0x14];
    /* 0x254 */ s16 unk254;
} Ea;

extern u8 D_80BCF8E4[];
void func_800B87A0(Ea *, s32, s32, f32, f32);

void func_80000FD8(Ea *this, s32 arg1) {
    func_800B87A0(this, arg1, 0xC, 300.0f, 300.0f);
    this->unk254 = 3;
    this->unk23C = D_80BCF8E4;
}
