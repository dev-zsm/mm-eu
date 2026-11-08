// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x116];
    /* 0x116 */ u16 unk116;
} Ea;

void func_80151E7C();
void func_80B25B48();

void func_80000674(Ea *this, s32 arg1, u16 arg2) {
    func_80151E7C(arg1, arg2, this);
    this->unk116 = arg2;
    func_80B25B48(this, arg2 & 0xFFFF);
}
