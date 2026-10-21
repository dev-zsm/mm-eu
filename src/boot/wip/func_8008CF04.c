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

typedef struct {
    u8 pad0[0x18];
    u16 unk18;
    u8 unk1A;
    u8 unk1B;
    u16 unk1C;
    u16 unk1E;
} Buf;

s32 func_80092DA0(void *a, s32 b);
s32 func_80090DE0(s32 a, s32 b, u16 c, void *d);
void func_8008C954(void *a, u16 *b, u16 *c);
s32 func_8008CA50(void *a, void *b, void *c);
s32 func_8008CDA0(void *a, void *b);
void func_80091460(void *a, void *b, s32 c);

s32 func_8008CF04(Ctx *arg0) {
    u16 sp6E;
    u16 sp6C;
    Buf sp4C;
    Buf sp28;
    Buf *var_s1;
    s32 temp_v0;
    u8 temp_t7;

    if (arg0->unk65 != 0) {
        temp_v0 = func_80092DA0(arg0, 0);
        if (temp_v0 != 0) {
            return temp_v0;
        }
    }
    temp_v0 = func_80090DE0(arg0->unk4, arg0->unk8, 1, &sp4C);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    func_8008C954(&sp4C, &sp6E, &sp6C);
    var_s1 = &sp4C;
    if (sp4C.unk1C != sp6E || sp4C.unk1E != sp6C) {
        temp_v0 = func_8008CDA0(arg0, &sp4C);
        if (temp_v0 == 0xA) {
            temp_v0 = func_8008CA50(arg0, &sp4C, &sp28);
            if (temp_v0 != 0) {
                return temp_v0;
            }
            var_s1 = &sp28;
        } else if (temp_v0 != 0) {
            return temp_v0;
        }
    }
    if (!(var_s1->unk18 & 1)) {
        temp_v0 = func_8008CA50(arg0, var_s1, &sp28);
        if (temp_v0 != 0) {
            return temp_v0;
        }
        var_s1 = &sp28;
        if (!(sp28.unk18 & 1)) {
            return 0xB;
        }
    }
    func_80091460(var_s1, arg0->unkC, 0x20);
    arg0->unk4C = var_s1->unk1B;
    arg0->unk50 = 0x10;
    arg0->unk54 = 8;
    temp_t7 = var_s1->unk1A;
    arg0->unk60 = (temp_t7 & 0xFF) * 2 + 3;
    arg0->unk58 = (temp_t7 & 0xFF) * 8 + 8;
    arg0->unk5C = arg0->unk58 + (temp_t7 & 0xFF) * 8;
    arg0->unk64 = temp_t7;
    temp_v0 = func_80090DE0(arg0->unk4, arg0->unk8, 7, arg0->unk2C);
    if (temp_v0 != 0) {
        return temp_v0;
    }
    return 0;
}
