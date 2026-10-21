// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern u8 D_8009E9A0;

void func_80089C90(void);
void func_80089CD4(void);
void func_80088070(s32, s32, s32);
void func_8008AF10(s32, void *);
s32 func_8008F2A0(u8 *, s32);
s32 func_80091240(u16, u16);
void func_80091460(u8 *, s32, s32);
s32 func_800928D0(s32, s32, u8 *);

s32 func_8008F970(s32 arg0, s32 arg1, u16 arg2, s32 arg3) {
    u8 sp63;
    s32 sp48;
    s32 sp44;
    s32 temp_v0;
    s32 var_s3;
    s32 var_s5;
    u8 *var_s0;
    u8 *temp_s2;
    s32 var_v0;
    s32 temp_a0;

    var_s5 = 2;
    func_80089C90();
    sp44 = arg2 << 5;
    sp48 = arg2 >> 3;
loop_1:
    var_s0 = &D_8009E9A0;
    if ((D_8009D2E0 != 9) || (arg1 != D_800981A0)) {
        D_8009D2E0 = 9;
        D_800981A0 = arg1;
        var_v0 = 0;
        if (arg1 > 0) {
            temp_a0 = arg1 & 3;
            if (temp_a0 != 0) {
                do {
                    var_v0 += 1;
                    *var_s0 = 0;
                    var_s0 += 1;
                } while (temp_a0 != var_v0);
                if (var_v0 != arg1) {
                    goto loop_9;
                }
            } else {
                do {
loop_9:
                    var_v0 += 4;
                    var_s0[0] = 0;
                    var_s0[1] = 0;
                    var_s0[2] = 0;
                    var_s0[3] = 0;
                    var_s0 += 4;
                } while (var_v0 != arg1);
            }
        }
        *(s32 *)(&D_8009E9A0 + 0x3C) = 1;
        var_s0[0] = 0xFF;
        var_s0[1] = 3;
        var_s0[2] = 0x25;
        var_s0[3] = 9;
        var_s0[0x2A] = 0xFF;
        var_s0[0x2B] = 0xFE;
    } else {
        var_s0 = &D_8009E9A0 + arg1;
    }
    var_s0[4] = sp48;
    var_s0[5] = func_80091240(arg2, arg2) | sp44;
    func_8008AF10(1, &D_8009E9A0);
    func_80088070(arg0, 0, 1);
    func_8008AF10(0, &D_8009E9A0);
    func_80088070(arg0, 0, 1);
    temp_s2 = var_s0 + 6;
    var_s3 = (var_s0[2] & 0xC0) >> 4;
    if (var_s3 == 0) {
        if (var_s0[0x2A] != func_8008F2A0(temp_s2, 0x24)) {
            temp_v0 = func_800928D0(arg0, arg1, &sp63);
            var_s3 = temp_v0;
            if (temp_v0 == 0) {
                var_s3 = 4;
                goto block_18;
            }
        } else {
            func_80091460(temp_s2, arg3, 0x24);
            goto block_18;
        }
    } else {
        var_s3 = 1;
block_18:
        if (var_s3 == 4) {
            if (var_s5 >= 0) {
                var_s5 -= 1;
                goto loop_1;
            }
        }
    }
    func_80089CD4();
    return var_s3;
}
