// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct G {
    /* 0x000 */ u8 pad0[0xF2D];
    /* 0xF2D */ u8 unkF2D;
} G;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x120];
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u8 pad124[0x1B4];
    /* 0x2D8 */ void *unk2D8;
} Ea;

extern G D_801E6EF0;
extern u8 D_80BB0470[];
s32 func_800B877C();
void func_800B87A0(Ea *, s32, s32, f32, f32);

void func_80000D1C(Ea *this, s32 arg1) {
    if (func_800B877C(this, arg1) != 0) {
        this->unk120 = 0;
        D_801E6EF0.unkF2D |= 2;
        this->unk2D8 = D_80BB0470;
    } else {
        func_800B87A0(this, arg1, 0xC, 300.0f, 300.0f);
    }
}
