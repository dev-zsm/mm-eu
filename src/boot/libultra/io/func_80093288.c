// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 pad0;
    s32 unk4;
    s32 unk8;
} Ctx;

s32 __osPfsSelectBank(Ctx *c, s32 x);
s32 __osContRamRead(s32 a, s32 b, u16 c, u8 *d);
s32 __osContRamWrite(s32 a, s32 b, u16 c, u8 *d, s32 e);
s32 bcmp(u8 *a, u8 *b, s32 n);

s32 __osPfsCheckRamArea(Ctx *arg0) {
    s32 ret;
    s32 i;
    u8 pattern[0x20];
    u8 readback[0x20];
    u8 backup[0x20];

    ret = __osPfsSelectBank(arg0, 0);
    if (ret != 0) {
        return ret;
    }
    ret = __osContRamRead(arg0->unk4, arg0->unk8, 0, backup);
    if (ret != 0) {
        return ret;
    }
    for (i = 0; i < 0x20; i++) {
        pattern[i] = i;
    }
    ret = __osContRamWrite(arg0->unk4, arg0->unk8, 0, pattern, 0);
    if (ret != 0) {
        return ret;
    }
    ret = __osContRamRead(arg0->unk4, arg0->unk8, 0, readback);
    if (ret != 0) {
        return ret;
    }
    if (bcmp(pattern, readback, 0x20) != 0) {
        return 0xB;
    }
    return __osContRamWrite(arg0->unk4, arg0->unk8, 0, backup, 0);
}
