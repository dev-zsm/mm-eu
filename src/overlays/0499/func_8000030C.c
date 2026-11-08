// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x98];
    /* 0x98 */ f32 unk98;
} Ea;

s32 func_800B70A4();
s32 func_800B7164();

s32 func_8000030C(Ea *this, s32 arg1) {
    if (this->unk98 < 100.0f && func_800B70A4(this, 0x3000, arg1) != 0 && func_800B7164(this, 0x2000) != 0) {
        return 1;
    }
    return 0;
}
