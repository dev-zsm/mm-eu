// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x32];
    /* 0x032 */ s16 unk32;
    /* 0x034 */ u8 pad34[0x5E];
    /* 0x092 */ s16 unk92;
    /* 0x094 */ u8 pad94[0x1E4];
    /* 0x278 */ void *unk278;
    /* 0x27C */ u8 pad27C[8];
    /* 0x284 */ s16 unk284;
    /* 0x286 */ u8 pad286[0xC7F];
    /* 0xF05 */ u8 unkF05;
} Ea;

extern u8 D_80A5D74C[];
void func_80A5C360();
void func_800B8C4C();

void func_800016B0(Ea *this) {
    func_80A5C360(this, 5);
    this->unk32 = this->unk92;
    func_800B8C4C(this, 0x1806);
    this->unkF05 |= 4;
    this->unk284 = 4;
    this->unk278 = D_80A5D74C;
}
