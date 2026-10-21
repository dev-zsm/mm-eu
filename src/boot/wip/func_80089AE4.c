// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 pad0C[0x65 - 0x0C];
    u8 unk65;
} Obj;

extern u8 D_8009D180[];
s32 func_80092DA0(Obj *o, s32 x);
s32 func_80090DE0(s32 a, s32 b, s32 c, u8 *d);
void func_800899D8(s32 count, u8 *buf);

s32 func_80089AE4(s32 a0, Obj *a1, s32 a2) {
    s32 v;
    u8 sp24[0x20];

    a1->unk4 = a0;
    a1->unk65 = 0xFF;
    a1->unk0 = 0;
    a1->unk8 = a2;

    v = func_80092DA0(a1, 0xFE);
    if (v == 2) {
        v = func_80092DA0(a1, 0x80);
    }
    if (v != 0) {
        return v;
    }

    v = func_80090DE0(a0, a2, 0x400, sp24);
    if (v == 2) {
        v = 4;
    }
    if (v != 0) {
        return v;
    }
    if (sp24[0x1F] == 0xFE) {
        return 0xB;
    }

    v = func_80092DA0(a1, 0x80);
    if (v == 2) {
        v = 4;
    }
    if (v != 0) {
        return v;
    }
    v = func_80090DE0(a0, a2, 0x400, sp24);
    if (v == 2) {
        v = 4;
    }
    if (v != 0) {
        return v;
    }
    if (sp24[0x1F] != 0x80) {
        return 0xB;
    }
    if (!(a1->unk0 & 8)) {
        func_800899D8(a2, D_8009D180 + (a2 << 6));
    }
    a1->unk0 = 8;
    return 0;
}
