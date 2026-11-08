// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x1F8];
    /* 0x200 */ void *unk200;
    /* 0x204 */ u8 pad204[0x16];
    /* 0x21A */ s16 unk21A;
} Ea;

extern u8 D_80BC0588[];
void func_800B8C4C();

void func_80000748(Ea *this) {
    this->unk4 |= 0x10;
    this->unk4 |= 0x08000000;
    func_800B8C4C(this, 0x387C);
    func_800B8C4C(this, 0x3881);
    this->unk21A = 2;
    this->unk200 = D_80BC0588;
}
