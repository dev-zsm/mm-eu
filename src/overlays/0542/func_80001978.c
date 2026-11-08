// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct V {
    s32 x;
    s32 y;
    s32 z;
} V;

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x24];
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ u8 pad30[0xC];
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
} Ea;

extern V D_80B8F274;
void func_80182B28();

void func_80001978(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Ea *arg4) {
    s32 pad;
    V sp18;

    sp18 = D_80B8F274;
    if (arg1 == 7) {
        arg4->unk3C = arg4->unk24;
        arg4->unk40 = arg4->unk28;
        arg4->unk44 = arg4->unk2C;
        func_80182B28(&sp18, &arg4->unk3C);
    }
}
