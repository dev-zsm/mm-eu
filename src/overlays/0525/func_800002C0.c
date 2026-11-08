// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct E {
    /* 0x0 */ s32 unk0;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
} E;

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s16 unk1C;
} Ea;

extern E D_80B7AE80[];
void func_80131AF8();
void func_800BDD44();

void func_800002C0(Ea *this, s32 arg1) {
    s32 pad[2];
    E *e = &D_80B7AE80[this->unk1C & 1];

    func_80131AF8(arg1, e->unk4, this);
    func_800BDD44(arg1, e->unk0);
}
