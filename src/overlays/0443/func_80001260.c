// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x210];
    /* 0x210 */ f32 unk210[1];
} Ea;

extern f32 D_80ADB280;
extern f32 D_80ADB284;

s32 func_80001260(Ea *this, s32 i) {
    f32 limit = D_80ADB280;

    this->unk210[i] -= D_80ADB284;
    if (this->unk210[i] <= limit) {
        this->unk210[i] = limit;
        return 1;
    }
    return 0;
}
