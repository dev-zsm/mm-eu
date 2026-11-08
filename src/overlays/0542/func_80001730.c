// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x148];
    /* 0x148 */ void (*unk148)(struct Ea *, s32);
} Ea;

void func_800B763C(s32, Ea *, f32, f32, f32, s32);
void func_80B8DB94();

void func_80001730(Ea *this, s32 arg1) {
    this->unk148(this, arg1);
    func_800B763C(arg1, this, 0.0f, 0.0f, 0.0f, 4);
    func_80B8DB94(this, arg1);
}
