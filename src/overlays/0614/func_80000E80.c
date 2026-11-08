// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x284];
    /* 0x284 */ void *unk284;
    /* 0x288 */ u8 pad288[0x18];
    /* 0x2A0 */ s16 unk2A0;
    /* 0x2A2 */ u8 pad2A2[0x4E];
    /* 0x2F0 */ s32 unk2F0;
} Ea;

extern u8 D_80BE3DDC[];
void func_80BE3234(Ea *, s32, f32);
void func_80BE33FC();

void func_80000E80(Ea *this) {
    this->unk2F0 = 0;
    func_80BE3234(this, 0x13, 1.0f);
    func_80BE33FC(this);
    this->unk2A0 = 1;
    this->unk284 = D_80BE3DDC;
}
