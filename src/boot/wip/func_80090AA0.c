// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern s8 D_8009E9A0;

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void osRecvMesg(s32 a, s32 b, s32 c);
void __osSiRawStartDma(s32 a, s8 *b);
s8 __osContAddressCrc(u16 a, u8 b);
s32 __osVoiceGetStatus(s32 a, s32 b, u8 *c);

s32 __osVoiceSetADConverter(s32 arg0, s32 arg1, u8 arg2) {
    s32 sp64;
    u8 sp5B;
    s32 sp48;
    s8 *var_s2;
    s8 *var_s0;
    s32 *var_s6;
    u8 *var_s5;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    s32 temp_a0;
    s32 temp_v0;
    s32 retry;

    var_s3 = 2;
    __osSiGetAccess();
    sp48 = (arg2 * 8) & 0xFFFF;
    var_s2 = &D_8009E9A0;
    var_s5 = &D_8009D2E0;
    var_s6 = &D_800981A0;
loop_1:
    retry = 0;
    var_s0 = var_s2;
    if ((*var_s5 != 0xD) || (arg1 != *var_s6)) {
        *var_s5 = 0xD;
        *var_s6 = arg1;
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
        ((s32 *) var_s2)[0xF] = 1;
        var_s0[0] = 3;
        var_s0[1] = 1;
        var_s0[2] = 0xD;
        var_s0[5] = 0;
        var_s0[6] = 0xFE;
    } else {
        var_s0 = var_s2 + arg1;
    }
    var_s0[3] = arg2;
    var_s0[4] = __osContAddressCrc(sp48, arg2);
    __osSiRawStartDma(1, var_s2);
    osRecvMesg(arg0, 0, 1);
    __osSiRawStartDma(0, var_s2);
    osRecvMesg(arg0, 0, 1);
    var_v1 = (s32) (var_s0[1] & 0xC0) >> 4;
    if (var_v1 != 0) {
        var_v1 = 1;
    } else if (var_s0[5] & 1) {
        temp_v0 = __osVoiceGetStatus(arg0, arg1, &sp5B);
        var_v1 = temp_v0;
        if (temp_v0 == 0) {
            var_v1 = 4;
            retry = 1;
        }
    }
    if (retry != 0) {
        if (var_s3 >= 0) {
            var_s3 -= 1;
            goto loop_1;
        }
        var_s3 -= 1;
    }
    sp64 = var_v1;
    __osSiRelAccess();
    return sp64;
}
