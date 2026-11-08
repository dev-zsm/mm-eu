// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Foo {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ u8 unk144[0x14C];
    /* 0x290 */ void (*unk290)(struct Foo *, s32);
    /* 0x294 */ u8 pad294[0x5C];
    /* 0x2F0 */ s32 unk2F0;
} Foo;

void func_80137070();

void func_8000016C(Foo *this, s32 arg1) {
    func_80137070(&this->unk144);
    this->unk2F0 = this->unk2F0;
    this->unk290(this, arg1);
}
