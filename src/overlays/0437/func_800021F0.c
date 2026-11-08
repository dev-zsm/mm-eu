// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct V {
    f32 x;
    f32 y;
    f32 z;
} V;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ V unk24;
    /* 0x030 */ u8 pad30[0x158];
    /* 0x188 */ void *unk188;
    /* 0x18C */ u8 pad18C[0x198];
    /* 0x324 */ V unk324[6];
    /* 0x36C */ s32 unk36C;
} Ea;

extern u8 D_80AD33E8[];
void func_800FF30C();

void func_800021F0(Ea *this, s32 arg1) {
    if (this->unk36C < 6) {
        func_800FF30C(&this->unk324[this->unk36C], &this->unk24);
        this->unk36C += 1;
    }
    this->unk188 = D_80AD33E8;
}
