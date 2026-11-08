// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ s32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02C */ f32 unk2C;
    /* 0x030 */ u8 pad30[0x164];
    /* 0x194 */ s32 unk194;
} Ea;

void func_800BA9E4(s32, s32, s32, s32, f32, f32, s32, s32, s32, s32);

void func_80000020(Ea *this, s32 arg1) {
    if (this->unk194 == 0) {
        func_800BA9E4(arg1 + 0x1CA0, arg1, 0x205, this->unk24, this->unk28, this->unk2C, 0, 0, 0, 0);
        this->unk194 = 1;
    }
}
