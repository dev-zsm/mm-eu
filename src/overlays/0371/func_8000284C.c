// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ob {
    /* 0x000 */ u8 pad0[0x19C];
    /* 0x19C */ s32 unk19C;
} Ob;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x120];
    /* 0x120 */ s32 unk120;
    /* 0x124 */ u8 pad124[0x20];
    /* 0x144 */ void *unk144;
    /* 0x148 */ u8 pad148[0x1F8];
    /* 0x340 */ Ob *unk340[1];
    /* 0x344 */ u8 pad344[8];
    /* 0x34C */ u8 unk34C;
} Ea;

extern u8 D_80A72CAC[];
s32 func_800B877C();
void func_800B87A0(Ea *, s32, s32, f32, f32);

void func_8000284C(Ea *this, s32 arg1) {
    if (func_800B877C(this, arg1) != 0) {
        this->unk120 = 0;
        this->unk144 = D_80A72CAC;
    } else {
        func_800B87A0(this, arg1, this->unk340[this->unk34C]->unk19C, 300.0f, 300.0f);
    }
}
