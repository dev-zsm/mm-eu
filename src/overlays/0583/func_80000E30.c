// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x200];
    /* 0x200 */ void *unk200;
    /* 0x204 */ u8 pad204[0x16];
    /* 0x21A */ s16 unk21A;
    /* 0x21C */ s16 unk21C;
} Ea;

extern u8 D_80BC0C74[];
void func_800B5B64();
void func_80BBFF54();

void func_80000E30(Ea *this, s32 arg1) {
    s16 a = this->unk21C;

    if (a >= 0) {
        func_800B5B64(arg1, a);
    }
    func_80BBFF54(this, 8);
    this->unk21A = 5;
    this->unk200 = D_80BC0C74;
}
