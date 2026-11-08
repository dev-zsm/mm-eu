// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x2D8];
    /* 0x2D8 */ s16 unk2D8;
} Ea;

s32 func_80BB8114();
s32 func_80BB819C();
s32 func_80BB8224();

s32 func_80000B18(Ea *this, s32 arg1, u8 *arg2) {
    s32 r;

    this->unk2D8 = 0;
    switch (*arg2) {
        case 1:
            r = func_80BB8114(this, arg1, arg2);
            break;
        case 2:
            r = func_80BB819C(this, arg1, arg2);
            break;
        case 3:
            r = func_80BB8224(this, arg1, arg2);
            break;
        default:
            r = 0;
            break;
    }
    return r;
}
