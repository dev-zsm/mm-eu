// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x124];
    /* 0x124 */ s32 unk124;
} Ea;

s32 func_8013DD10();
f32 func_800B6BA0();

s32 func_80001240(Ea *this, s32 arg1) {
    this->unk124 = func_8013DD10(arg1, 0, 1, 0xA7);
    if (this->unk124 != 0 && func_800B6BA0(this, this->unk124) < 250.0f) {
        return 1;
    }
    return 0;
}
