// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[4];
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x13C];
    /* 0x144 */ u8 unk144[0x1C0];
    /* 0x304 */ void *unk304;
} Ea;

extern u8 D_80B26960[];
void func_80137070();
s32 func_800B8400();
void func_80B25C18();

void func_80001454(Ea *this, s32 arg1) {
    func_80137070(this->unk144);
    if (func_800B8400(this, arg1) != 0) {
        this->unk304 = D_80B26960;
        this->unk4 &= ~0x100;
    }
    func_80B25C18(this, arg1);
}
