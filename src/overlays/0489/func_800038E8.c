// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Pl {
    /* 0x00000 */ u8 pad0[0x18875];
    /* 0x18875 */ u8 unk18875;
    /* 0x18876 */ u8 pad18876[4];
    /* 0x1887A */ s16 unk1887A;
    /* 0x1887C */ u8 pad1887C[3];
    /* 0x1887F */ u8 unk1887F;
} Pl;

typedef struct G {
    /* 0x0000 */ u8 pad0[0xF51];
    /* 0x0F51 */ u8 unkF51;
    /* 0x0F52 */ u8 padF52[0x2FF8];
    /* 0x3F4A */ u16 unk3F4A;
    /* 0x3F4C */ u8 pad3F4C[9];
    /* 0x3F55 */ u8 unk3F55;
} G;

extern G D_801E6EF0;
void func_80B2C034();

void func_800038E8(s32 arg0, Pl *arg1) {
    arg1->unk1887A = 0x6400;
    D_801E6EF0.unk3F4A = 0xFFF3;
    arg1->unk18875 = 0x14;
    arg1->unk1887F = 0x48;
    D_801E6EF0.unk3F55 = 0x48;
    D_801E6EF0.unkF51 |= 0x10;
    func_80B2C034(arg0, arg1);
}
