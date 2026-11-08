// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x280];
    /* 0x2B4 */ s16 unk2B4;
} Ea;

void func_800B8AD4(s32, Ea *, f32, s16, f32, s32);
void func_80B43B20();

void func_80000500(Ea *this, s32 arg1) {
    if (this->unk2B4 == 0) {
        func_800B8AD4(arg1, this, 10.0f, this->unk32, 10.0f, 8);
        func_80B43B20(this);
    }
}
