// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    s32 unk4;
    s32 unk8;
    u8 unkC[0x20];
    u8 unk2C[0x20];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    u8 unk64;
    u8 unk65;
} Ctx;

s32 __osPfsSelectBank(void *a, s32 b);
s32 __osContRamRead(s32 a, s32 b, u16 c, void *d);
s32 bcmp(void *a, void *b, s32 c);

s32 __osCheckId(Ctx *arg0) {
    u8 sp28[0x20];
    s32 var_v0;
    s32 var_v1;

    if (arg0->unk65 != 0) {
        var_v0 = __osPfsSelectBank(arg0, 0);
        var_v1 = var_v0;
        if (var_v0 == 2) {
            var_v0 = __osPfsSelectBank(arg0, 0);
            var_v1 = var_v0;
        }
        if (var_v0 != 0) {
            return var_v1;
        }
    }
    var_v0 = __osContRamRead(arg0->unk4, arg0->unk8, 1, sp28);
    if (var_v0 != 0) {
        if (var_v0 != 2) {
            return var_v0;
        }
        var_v0 = __osContRamRead(arg0->unk4, arg0->unk8, 1, sp28);
        if (var_v0 != 0) {
            return var_v0;
        }
    }
    if (bcmp(arg0->unkC, sp28, 0x20) != 0) {
        return 2;
    }
    return 0;
}
