// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ob {
    /* 0x00 */ u8 pad0[0x30];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
} Ob;

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x31C];
    /* 0x31C */ f32 unk31C;
    /* 0x320 */ f32 unk320;
    /* 0x324 */ f32 unk324;
    /* 0x328 */ u8 pad328[0x20];
    /* 0x348 */ f32 unk348;
} Ea;

Ob *func_801812C4();

void func_80000000(Ea *this) {
    Ob *o = func_801812C4();

    o->unk30 = o->unk30 + this->unk348 * this->unk31C;
    o->unk34 = o->unk34 + this->unk348 * this->unk320;
    o->unk38 = o->unk38 + this->unk348 * this->unk324;
}
