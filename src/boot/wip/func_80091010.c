// FLAGS: -O2 -g3 -mips2
#include "types.h"

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void osRecvMesg(s32 a0, s32 a1, s32 a2);
void __osSiRawStartDma(s32 a0, s8 *a1);
s32 __osContAddressCrc(s32 a0, s32 a1);
s32 __osVoiceContDataCrc(s8 *a0, s32 a1);
s32 __osVoiceGetStatus(s32 a0, s32 a1, s8 *a2);
void bcopy(s8 *a0, s8 *a1, s32 a2);

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern s8 D_8009E9A0[];

s32 __osVoiceContWrite20(s32 arg0, s32 arg1, u16 arg2, s8 *arg3) {
    s32 sp6C;
    s8 sp6B;
    s32 sp4C;
    s32 sp48;
    s8 *base;
    s8 *var_s0;
    s32 var_s4;
    s32 var_v0;
    s32 var_v1;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_s2;

    var_s4 = 2;
    __osSiGetAccess();
    sp48 = arg2 << 5;
    sp4C = (s32) arg2 >> 3;
    base = D_8009E9A0;
loop_1:
    var_s0 = base;
    if (*(u8 *)&D_8009D2E0 != 0xA || arg1 != *(s32 *)&D_800981A0) {
        *(u8 *)&D_8009D2E0 = 0xA;
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
        var_s0[1] = 0x17;
        var_s0[2] = 1;
        var_s0[3] = 0xA;
        var_s0[0x1A] = 0xFF;
        var_s0[0x1B] = 0xFE;
    } else {
        var_s0 = base + arg1;
    }
    var_s0[4] = sp4C;
    var_s0[5] = __osContAddressCrc(arg2 & 0xFFFF, arg2) | sp48;
    bcopy(arg3, var_s0 + 6, 0x14);
    __osSiRawStartDma(1, base);
    temp_s2 = __osVoiceContDataCrc(arg3, 0x14) & 0xFF;
    osRecvMesg(arg0, 0, 1);
    __osSiRawStartDma(0, base);
    osRecvMesg(arg0, 0, 1);
    var_v1 = (var_s0[2] & 0xC0) >> 4;
    if (var_v1 == 0) {
        if (var_s0[0x1A] != temp_s2) {
            temp_v0 = __osVoiceGetStatus(arg0, arg1, &sp6B);
            var_v1 = temp_v0;
            if (temp_v0 == 0) {
                var_v1 = 4;
                goto block_17;
            }
        } else {
            goto block_17;
        }
    } else {
        var_v1 = 1;
block_17:
        if (var_v1 == 4) {
            var_s4 -= 1;
            if (var_s4 >= 0) {
                goto loop_1;
            }
        }
    }
    sp6C = var_v1;
    __osSiRelAccess();
    return sp6C;
}
