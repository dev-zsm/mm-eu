// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern u8 D_8009E9A0;

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void osRecvMesg(s32, s32, s32);
void __osSiRawStartDma(s32, void *);
s32 __osVoiceContDataCrc(u8 *, s32);
s32 __osContAddressCrc(u16, u16);
void bcopy(u8 *, s32, s32);
s32 __osVoiceGetStatus(s32, s32, u8 *);

s32 __osVoiceContRead36(s32 arg0, s32 arg1, u16 arg2, s32 arg3) {
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
    __osSiGetAccess();
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
    var_s0[5] = __osContAddressCrc(arg2, arg2) | sp44;
    __osSiRawStartDma(1, &D_8009E9A0);
    osRecvMesg(arg0, 0, 1);
    __osSiRawStartDma(0, &D_8009E9A0);
    osRecvMesg(arg0, 0, 1);
    temp_s2 = var_s0 + 6;
    var_s3 = (var_s0[2] & 0xC0) >> 4;
    if (var_s3 == 0) {
        if (var_s0[0x2A] != __osVoiceContDataCrc(temp_s2, 0x24)) {
            temp_v0 = __osVoiceGetStatus(arg0, arg1, &sp63);
            var_s3 = temp_v0;
            if (temp_v0 == 0) {
                var_s3 = 4;
                goto block_18;
            }
        } else {
            bcopy(temp_s2, arg3, 0x24);
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
    __osSiRelAccess();
    return var_s3;
}
