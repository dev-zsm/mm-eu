// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ u8 unk144[0x44];
    /* 0x188 */ void (*unk188)(struct Ea *, s32);
} Ea;

void func_80137070();
void func_800B763C(s32, Ea *, f32, f32, f32, s32);

void func_80000238(Ea *this, s32 arg1) {
    this->unk188(this, arg1);
    func_80137070(&this->unk144);
    func_800B763C(arg1, this, 30.0f, 12.0f, 0.0f, 4);
}
