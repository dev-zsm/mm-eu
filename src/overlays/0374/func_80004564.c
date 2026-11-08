// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct E {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u8 pad2[2];
    /* 0x4 */ f32 unk4;
} E;

extern f32 D_80A7E328;

void func_80004564(E *arg0, f32 arg1, f32 *arg2) {
    f32 cx;
    f32 px;
    f32 py;

    do {
        arg0++;
        cx = arg0->unk0;
    } while (cx < arg1);
    px = arg0[-1].unk0;
    py = arg0[-1].unk4;
    *arg2 = (((arg0->unk4 - py) * ((arg1 - px) / (cx - px))) + py) * D_80A7E328;
}
