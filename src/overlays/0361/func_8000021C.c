// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Ea {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s16 unk1C;
} Ea;

Ea *func_8013DD10();
s32 func_800B5B20();

s32 func_8000021C(s32 arg0) {
    s32 pad;
    s32 r = 0;
    Ea *p = func_8013DD10(arg0, 0, 4, 0x17F);

    if (p != NULL) {
        if (func_800B5B20(arg0, (p->unk1C >> 7) & 0x7F) != 0) {
            r = 2;
        } else {
            r = 1;
        }
    }
    return r;
}
