// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 pad0;
    s32 unk4;
    s32 unk8;
} Ctx;

s32 func_80092DA0(Ctx *c, s32 x);
s32 func_80090DE0(s32 a, s32 b, u16 c, u8 *d);
s32 func_80093F40(s32 a, s32 b, u16 c, u8 *d, s32 e);
s32 func_800904A0(u8 *a, u8 *b, s32 n);

s32 func_80093288(Ctx *arg0) {
    u8 sp70[0x20];
    u8 sp50[0x20];
    u8 sp30[0x20];
    s32 ret;
    s32 i;
    u8 *p;

    ret = func_80092DA0(arg0, 0);
    if (ret != 0) {
        return ret;
    }
    ret = func_80090DE0(arg0->unk4, arg0->unk8, 0, sp30);
    if (ret != 0) {
        return ret;
    }
    p = sp70; i = 0; do { p[0] = i; p[1] = i + 1; p[2] = i + 2; p[3] = i + 3; p += 4; i += 4; } while (i != 0x20);
    ret = func_80093F40(arg0->unk4, arg0->unk8, 0, sp70, 0);
    if (ret != 0) {
        return ret;
    }
    ret = func_80090DE0(arg0->unk4, arg0->unk8, 0, sp50);
    if (ret != 0) {
        return ret;
    }
    if (func_800904A0(sp70, sp50, 0x20) != 0) {
        return 0xB;
    }
    return func_80093F40(arg0->unk4, arg0->unk8, 0, sp30, 0);
}
