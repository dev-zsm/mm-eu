// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x120];
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u8 pad124[0x1D4];
    /* 0x2F8 */ void *unk2F8;
} Ea;

extern u8 D_80B7DE48[];
s32 func_800B877C();
void func_800B87A0(Ea *, s32, s32, f32, f32);

void func_800029E4(Ea *this, s32 arg1) {
    if (func_800B877C(this, arg1) != 0) {
        this->unk120 = 0;
        this->unk2F8 = D_80B7DE48;
    } else {
        func_800B87A0(this, arg1, 2, 10000.0f, 50.0f);
    }
}
