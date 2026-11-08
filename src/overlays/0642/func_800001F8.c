// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ void *unk144;
    /* 0x148 */ u8 pad148[0x18];
    /* 0x160 */ s32 unk160;
} Ea;

extern u8 D_80BFED1C[];
extern u8 D_80BFF868[];
void func_800FF8DC();
s32 func_8012F9A8();
void func_800B6490();

void func_800001F8(Ea *this, s32 arg1) {
    s32 r;

    func_800FF8DC(this, D_80BFF868);
    r = func_8012F9A8(arg1 + 0x17D88, 0x146);
    this->unk160 = r;
    if (r < 0) {
        func_800B6490(this);
    } else {
        this->unk144 = D_80BFED1C;
    }
}
