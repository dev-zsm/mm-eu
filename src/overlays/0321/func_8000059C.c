// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ void (*unk144)(struct Ea *, s32);
} Ea;

void func_800B763C(s32, Ea *, f32, f32, f32, s32);
void func_80A1D9C0();
void func_80A1D940();

void func_8000059C(Ea *this, s32 arg1) {
    this->unk144(this, arg1);
    func_800B763C(arg1, this, 0.0f, 0.0f, 0.0f, 4);
    func_80A1D9C0(this, arg1);
    func_80A1D940(this, arg1);
}
