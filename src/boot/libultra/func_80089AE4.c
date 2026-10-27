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
s32 __osPfsSelectBank(Obj *o, s32 x);
s32 __osContRamRead(s32 a, s32 b, s32 c, u8 *d);
void __osMakeMotorData(s32 count, u8 *buf);

s32 osMotorInit(s32 a0, Obj *a1, s32 a2) {
    s32 v;
    u8 sp24[0x20];

    a1->unk4 = a0;
    a1->unk8 = a2;
    a1->unk65 = 0xFF;
    a1->unk0 = 0;

    v = __osPfsSelectBank(a1, 0xFE);
    if (v == 2) {
        v = __osPfsSelectBank(a1, 0x80);
    }
    if (v != 0) {
        return v;
    }

    v = __osContRamRead(a0, a2, 0x400, sp24);
    if (v == 2) {
        v = 4;
    }
    if (v != 0) {
        return v;
    }
    if (sp24[0x1F] == 0xFE) {
        return 0xB;
    }

    v = __osPfsSelectBank(a1, 0x80);
    if (v == 2) {
        v = 4;
    }
    if (v != 0) {
        return v;
    }
    v = __osContRamRead(a0, a2, 0x400, sp24);
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
        __osMakeMotorData(a2, D_8009D180 + (a2 << 6));
    }
    a1->unk0 = 8;
    return 0;
}
