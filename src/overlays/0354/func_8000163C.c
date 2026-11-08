// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct V3 {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ V3 unk24;
    /* 0x030 */ u8 pad30[0xC];
    /* 0x03C */ V3 unk3C;
    /* 0x048 */ u8 pad48[0x140];
    /* 0x188 */ void (*unk188)(struct Ea *, s32);
} Ea;

void func_80A4A7BC();

void func_8000163C(Ea *this, s32 arg1) {
    this->unk188(this, arg1);
    this->unk3C = this->unk24;
    *(f32 *)&this->unk3C.y = *(f32 *)&this->unk3C.y + 30.0f;
    func_80A4A7BC(this, arg1);
}
