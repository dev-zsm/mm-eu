// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_8009BDE8[];
extern s32 D_8009C1E8;
extern s32 D_8009C1EC;
extern u32 D_8009C1F0;
extern s32 D_8009C1F4;
extern u8 D_800984A0[];

void func_800807E0(s32 a, void *b, u32 c, s32 d);
void bcopy(s32 a, void *b, s32 c);
s32 osGetThreadPri(s32 a);
void osSetThreadPri(s32 a, s32 b);
void func_8008198C(void *a);

void *Yaz0_NextDMA(s32 arg0) {
    u8 *var_s0;
    u32 temp_a3;
    s32 temp_v0;
    u32 var_a2;
    s32 sp28;
    u8 *temp_a1;

    temp_a3 = D_8009C1E8 - arg0;
    temp_v0 = temp_a3 & 7;
    var_s0 = D_8009BDE8;
    if (temp_v0 != 0) {
        var_s0 = (D_8009BDE8 - temp_v0) + 8;
    }
    bcopy(arg0, var_s0, temp_a3);
    var_a2 = (D_8009C1E8 - (s32)var_s0) - temp_a3;
    if (D_8009C1F0 < var_a2) {
        var_a2 = D_8009C1F0;
    }
    temp_a1 = var_s0 + temp_a3;
    if (var_a2 != 0) {
        func_800807E0(D_8009C1EC, temp_a1, var_a2, temp_a3);
        D_8009C1EC += var_a2;
        D_8009C1F0 -= var_a2;
        if (D_8009C1F0 == 0) {
            D_8009C1F4 = (s32)(temp_a1 + var_a2);
        }
    } else {
        sp28 = osGetThreadPri(0);
        osSetThreadPri(0, 0x7F);
        func_8008198C(D_800984A0);
        osSetThreadPri(0, sp28);
    }
    return var_s0;
}
