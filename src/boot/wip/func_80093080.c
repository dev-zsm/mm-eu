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

void func_80089C90(void);
s32 func_80089CD4(void);
s32 func_8008B560(s32 a, s32 b);
void func_8008C954(u8 *a, u16 *b, u16 *c);
s32 func_8008CA50(Ctx *c, u8 *a, u8 *b);
s32 func_8008CDA0(Ctx *c, u8 *a);
s32 func_80090DE0(s32 a, s32 b, u16 c, u8 *d);
void func_80091460(u8 *a, u8 *b, s32 c);
s32 func_80092DA0(Ctx *c, s32 x);
s32 func_80093288(Ctx *c);
s32 func_80093390(Ctx *c);

s32 func_80093080(s32 arg0, Ctx *arg1, s32 arg2) {
    s32 sp6C;
    Blk sp20;
    u8 *sp44;
    Blk sp48;
    u16 sp68;
    u16 sp6A;
    s32 ret;
    s32 r;
    s32 t;

    func_80089C90();
    func_8008B560(arg0, arg2);
    sp6C = func_80089CD4();
    if (sp6C != 0) {
        return sp6C;
    }
    arg1->unk4 = arg0;
    arg1->unk0 = 0;
    arg1->unk8 = arg2;
    ret = func_80093288(arg1);
    if (ret != 0) {
        return ret;
    }
    ret = func_80092DA0(arg1, 0);
    if (ret != 0) {
        return ret;
    }
    ret = func_80090DE0(arg1->unk4, arg1->unk8, 1, (u8 *)&sp48);
    if (ret != 0) {
        return ret;
    }
    func_8008C954((u8 *)&sp48, &sp6A, &sp68);
    sp44 = (u8 *)&sp48;
    if (sp6A != sp48.h[2] || sp68 != sp48.h[3]) {
        r = func_8008CDA0(arg1, (u8 *)&sp48);
        if (r != 0) {
            arg1->unk0 |= 4;
            return r;
        }
    }
    if (!(sp48.h[0] & 1)) {
        r = func_8008CA50(arg1, (u8 *)&sp48, (u8 *)&sp20);
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
    func_80091460(sp44, arg1->unkC, 0x20);
    arg1->unk4C = sp44[0x1B];
    t = sp44[0x1A];
    arg1->unk50 = 0x10;
    arg1->unk54 = 8;
    arg1->unk60 = t * 2 + 3;
    arg1->unk58 = t * 8 + 8;
    arg1->unk5C = t * 16 + 8;
    arg1->unk64 = t;
    ret = func_80090DE0(arg1->unk4, arg1->unk8, 7, arg1->unk2C);
    if (ret != 0) {
        return ret;
    }
    ret = func_80093390(arg1);
    arg1->unk0 |= 1;
    return ret;
}
