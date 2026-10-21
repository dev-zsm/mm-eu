// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80089C90(void);
void func_80089CD4(void);
void func_80088070(s32 a0, s32 a1, s32 a2);
void func_8008AF10(s32 a0, s8 *a1);
s32 func_8008B560(s32 a0, s32 a1);
s32 func_80091240(s32 a0, s32 a1);
s32 func_80091310(s8 *a0);
void func_80091460(s8 *a0, s32 a1, s32 a2);

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern s8 D_8009E9A0[];

s32 func_80090DE0(s32 arg0, s32 arg1, u16 arg2, s32 arg3) {
    s32 sp40;
    s32 sp44;
    s8 *base;
    s8 *var_s0;
    s32 var_v0;
    s32 var_s3;
    s32 var_s5;
    s32 temp_a0;
    s32 temp_v0;
    s8 *temp_s2;

    var_s5 = 2;
    func_80089C90();
    sp40 = arg2 << 5;
    sp44 = (s32) arg2 >> 3;
    base = D_8009E9A0;
loop_1:
    var_s0 = base;
    if (*(u8 *)&D_8009D2E0 != 2 || arg1 != *(s32 *)&D_800981A0) {
        *(u8 *)&D_8009D2E0 = 2;
        *(s32 *)&D_800981A0 = arg1;
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
        *(s32 *)(base + 0x3C) = 1;
        var_s0[0] = 0xFF;
        var_s0[1] = 3;
        var_s0[2] = 0x21;
        var_s0[3] = 2;
        var_s0[0x26] = 0xFF;
        var_s0[0x27] = 0xFE;
    } else {
        var_s0 = base + arg1;
    }
    var_s0[4] = sp44;
    var_s0[5] = func_80091240(arg2 & 0xFFFF, arg2) | sp40;
    func_8008AF10(1, base);
    func_80088070(arg0, 0, 1);
    func_8008AF10(0, base);
    func_80088070(arg0, 0, 1);
    temp_s2 = var_s0 + 6;
    var_s3 = (var_s0[2] & 0xC0) >> 4;
    if (var_s3 == 0) {
        if (var_s0[0x26] != func_80091310(temp_s2)) {
            temp_v0 = func_8008B560(arg0, arg1);
            var_s3 = temp_v0;
            if (temp_v0 == 0) {
                var_s3 = 4;
                goto block_18;
            }
        } else {
            func_80091460(temp_s2, arg3, 0x20);
            goto block_18;
        }
    } else {
        var_s3 = 1;
block_18:
        if (var_s3 == 4) {
            var_s5 -= 1;
            if (var_s5 >= 0) {
                goto loop_1;
            }
        }
    }
    func_80089CD4();
    return var_s3;
}
