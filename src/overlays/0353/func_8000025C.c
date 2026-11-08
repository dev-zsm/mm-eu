// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Pl {
    /* 0x000 */ u8 pad0[0x39A];
    /* 0x39A */ s16 unk39A;
    /* 0x39C */ u8 pad39C[0xA];
    /* 0x3A6 */ s16 unk3A6;
} Pl;

s32 func_8013A8E0(s32, Pl *, s32, s32, s32, f32, f32, s32);

s32 func_8000025C(s32 arg0, Pl *arg1) {
    s32 r = func_8013A8E0(arg0, arg1, 8, (s32)arg1 + 0x3C, (s32)arg1 + 0xBC, 10.0f, 400.0f, 0x4000);

    if (r == 0) {
        arg1->unk39A = 1;
        arg1->unk3A6 = 3;
    }
    return r;
}
