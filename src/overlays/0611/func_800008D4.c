// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x144];
    /* 0x144 */ u8 unk144[0x2DE];
    /* 0x422 */ s16 unk422;
} Ea;

void func_80137070();
void func_80136480();

void func_800008D4(Ea *this, s32 arg1) {
    if (this->unk422 < 7) {
        func_80137070(&this->unk144);
    } else {
        func_80136480(arg1, &this->unk144);
    }
}
