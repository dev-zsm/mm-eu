// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x24];
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02C */ f32 unk2C;
    /* 0x030 */ s16 unk30;
    /* 0x032 */ s16 unk32;
    /* 0x034 */ s16 unk34;
    /* 0x036 */ u8 pad36[6];
    /* 0x03C */ f32 unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
    /* 0x048 */ s16 unk48;
    /* 0x04A */ s16 unk4A;
    /* 0x04C */ s16 unk4C;
    /* 0x04E */ u8 pad4E[0x182];
    /* 0x1D0 */ u8 pad1D0[1];
} Ea;

typedef struct Eb {
    /* 0x000 */ u8 pad0[0xC4];
    /* 0x0C4 */ f32 unkC4;
    /* 0x0C8 */ u8 padC8[0x168];
    /* 0x230 */ u16 unk230;
} Eb;

void func_80000634(Ea *thisx) {
    Eb *this = (Eb *)thisx;
    f32 v;

    if (this->unk230 & 1) {
        v = this->unkC4;
    } else {
        v = 58.0f;
    }
    thisx->unk3C = thisx->unk24;
    thisx->unk40 = thisx->unk28 + v;
    thisx->unk44 = thisx->unk2C;
    thisx->unk48 = thisx->unk30;
    thisx->unk4A = thisx->unk32;
    thisx->unk4C = thisx->unk34;
}
