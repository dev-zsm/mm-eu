// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x2B8];
    /* 0x2B8 */ u8 *unk2B8;
} Ea;

extern s32 (*D_80B89F14[])(struct Ea *, s32);
s32 func_80B899AC();

s32 func_80001584(Ea *this, s32 arg1) {
    s32 r = D_80B89F14[*this->unk2B8](this, arg1);

    if (r != 0) {
        this->unk2B8 += r * 4;
        return func_80B899AC(this, arg1);
    }
    return 0;
}
