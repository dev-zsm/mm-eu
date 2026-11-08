// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ f32 unk24[3];
    /* 0x030 */ u8 pad30[0x2D9];
    /* 0x309 */ u8 unk309;
} Ea;

void func_80B288F8();
void func_800B4A5C(s32, Ea *, f32);
void func_80B29E9C();

void func_8000154C(Ea *this, s32 arg1) {
    s32 pad;
    f32 y = this->unk24[1];

    func_80B288F8(this, &this->unk309, this->unk24);
    this->unk24[1] = y;
    func_800B4A5C(arg1, this, 50.0f);
    func_80B29E9C(this);
}
