// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x98];
    /* 0x98 */ f32 unk98;
    /* 0x9C */ f32 unk9C;
} Ea;

float fabsf(float);
#pragma intrinsic (fabsf)
s32 func_800B70A4();

s32 func_800007F8(Ea *this, s32 arg1) {
    if (this->unk98 < 80.0f && fabsf(this->unk9C) < 20.0f && func_800B70A4(this, 0x3000, arg1) != 0) {
        return 1;
    }
    return 0;
}
