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
s32 func_80093F40(s32 a, s32 b, u16 c, void *d, s32 e);
void func_8008C954(void *a, u16 *b, u16 *c);

s32 func_8008CDA0(Ctx *arg0, Buf *arg1) {
    u16 sp58[4];
    struct { u16 a; u16 b; } pr;
    u16 *var_s0;
    s32 var_s1;
    s32 var_s0_2;
    s32 temp_v0;

    if (arg0->unk65 != 0) {
        temp_v0 = func_80092DA0(arg0, 0);
        if (temp_v0 != 0) {
            return temp_v0;
        }
    }
    sp58[0] = 1;
    sp58[1] = 3;
    sp58[2] = 4;
    sp58[3] = 6;
    var_s1 = 1;
    var_s0 = &sp58[1];
    for (;;) {
        temp_v0 = func_80090DE0(arg0->unk4, arg0->unk8, *var_s0, arg1);
        if (temp_v0 != 0) {
            return temp_v0;
        }
        func_8008C954(arg1, &pr.b, &pr.a);
        if (pr.b == arg1->unk1C && pr.a == arg1->unk1E) {
            break;
        }
        var_s1 += 1;
        var_s0 += 1;
        if (var_s1 == 4) {
            break;
        }
    }
    if (var_s1 == 4) {
        return 0xA;
    }
    for (var_s0_2 = 0; var_s0_2 != 4; var_s0_2++) {
        if (var_s0_2 != var_s1) {
            temp_v0 = func_80093F40(arg0->unk4, arg0->unk8, sp58[var_s0_2], arg1, 1);
            if (temp_v0 != 0) {
                return temp_v0;
            }
        }
    }
    return 0;
}
