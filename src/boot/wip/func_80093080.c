// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
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
} Ctx;

typedef struct {
    u8 b[0x18];
    u16 h[4];
} Blk;

void __osSiGetAccess(void);
s32 __osSiRelAccess(void);
s32 __osPfsGetStatus(s32 a, s32 b);
void __osIdCheckSum(u8 *a, u16 *b, u16 *c);
s32 __osRepairPackId(Ctx *c, u8 *a, u8 *b);
s32 __osCheckPackId(Ctx *c, u8 *a);
s32 __osContRamRead(s32 a, s32 b, u16 c, u8 *d);
void bcopy(u8 *a, u8 *b, s32 c);
s32 __osPfsSelectBank(Ctx *c, s32 x);
s32 __osPfsCheckRamArea(Ctx *c);
s32 osPfsChecker(Ctx *c);

s32 osPfsInitPak(s32 arg0, Ctx *arg1, s32 arg2) {
    s32 sp6C;
    Blk sp20;
    u8 *sp44;
    Blk sp48;
    u16 sp68;
    u16 sp6A;
    s32 ret;
    s32 r;
    s32 t;

    __osSiGetAccess();
    __osPfsGetStatus(arg0, arg2);
    sp6C = __osSiRelAccess();
    if (sp6C != 0) {
        return sp6C;
    }
    arg1->unk4 = arg0;
    arg1->unk0 = 0;
    arg1->unk8 = arg2;
    ret = __osPfsCheckRamArea(arg1);
    if (ret != 0) {
        return ret;
    }
    ret = __osPfsSelectBank(arg1, 0);
    if (ret != 0) {
        return ret;
    }
    ret = __osContRamRead(arg1->unk4, arg1->unk8, 1, (u8 *)&sp48);
    if (ret != 0) {
        return ret;
    }
    __osIdCheckSum((u8 *)&sp48, &sp6A, &sp68);
    sp44 = (u8 *)&sp48;
    if (sp6A != sp48.h[2] || sp68 != sp48.h[3]) {
        r = __osCheckPackId(arg1, (u8 *)&sp48);
        if (r != 0) {
            arg1->unk0 |= 4;
            return r;
        }
    }
    if (!(sp48.h[0] & 1)) {
        r = __osRepairPackId(arg1, (u8 *)&sp48, (u8 *)&sp20);
        if (r != 0) {
            if (r == 0xA) {
                arg1->unk0 |= 4;
            }
            return r;
        }
        sp44 = (u8 *)&sp20;
        if (!(sp20.h[0] & 1)) {
            return 0xB;
        }
    }
    bcopy(sp44, arg1->unkC, 0x20);
    arg1->unk4C = sp44[0x1B];
    t = sp44[0x1A];
    arg1->unk50 = 0x10;
    arg1->unk54 = 8;
    arg1->unk60 = t * 2 + 3;
    arg1->unk58 = t * 8 + 8;
    arg1->unk5C = t * 16 + 8;
    arg1->unk64 = t;
    ret = __osContRamRead(arg1->unk4, arg1->unk8, 7, arg1->unk2C);
    if (ret != 0) {
        return ret;
    }
    ret = osPfsChecker(arg1);
    arg1->unk0 |= 1;
    return ret;
}
