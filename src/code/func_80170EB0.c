// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    s16 unk4;
    s16 unk6;
    u8 pad8[0xC];
    s32 unk14;
    s32 unk18;
    u8 pad1C[4];
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
} Rect;

void func_80170EB0(Rect *r, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    r->unk4 = arg1;
    r->unk6 = arg2;
    r->unk14 = arg3;
    r->unk18 = arg5;
    r->unk20 = arg4;
    r->unk24 = 0;
    r->unk26 = 0;
    r->unk28 = arg1 - 1;
    r->unk2A = arg2 - 1;
}
