// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x254];
    /* 0x254 */ void *unk254;
    /* 0x258 */ u8 pad258[6];
    /* 0x25E */ s16 unk25E;
    /* 0x260 */ u8 pad260[5];
    /* 0x265 */ u8 unk265;
    /* 0x266 */ u8 pad266[2];
    /* 0x268 */ s32 unk268;
    /* 0x26C */ u8 pad26C[8];
    /* 0x274 */ s16 unk274;
    /* 0x276 */ u8 pad276[2];
    /* 0x278 */ s16 unk278;
} Ea;

extern u8 D_801E7DF4;
extern u8 D_80ACD2F4[];
void func_80ACC23C();

void func_800011AC(Ea *this, s32 arg1) {
    if ((this->unk265 != 0 || (D_801E7DF4 & 0x20)) && this->unk268 != 2) {
        func_80ACC23C(this, 2);
    }
    this->unk25E = 0;
    this->unk274 = 0;
    this->unk278 = 1;
    this->unk254 = D_80ACD2F4;
}
