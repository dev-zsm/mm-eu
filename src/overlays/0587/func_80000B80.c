// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x000 */ u8 pad0[0x2FC];
    /* 0x2FC */ s16 unk2FC;
} Ea;

s32 func_80BC5CA4();
s32 func_80BC5D64();

s32 func_80000B80(Ea *this, s32 arg1, u8 *arg2) {
    s32 r;

    this->unk2FC = 0;
    switch (*arg2) {
        case 1:
            r = func_80BC5CA4(this, arg1, arg2);
            break;
        case 2:
            r = func_80BC5D64(this, arg1, arg2);
            break;
        default:
            r = 0;
            break;
    }
    return r;
}
