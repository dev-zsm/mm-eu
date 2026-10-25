// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void __osSiRawStartDma(s32 dir, u8 *pifRam);
u32 __osVoiceContDataCrc(u8 *data, s32 size);
u32 __osContAddressCrc(u16 address);
void bcopy(u8 *src, u8 *dst, s32 size);
void osRecvMesg(s32 mq, s32 msg, s32 flag);
s32 __osVoiceGetStatus(s32 mq, s32 channel, u8 *status);

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern u8 D_8009E9A0[];

s32 __osVoiceContWrite4(s32 mq, s32 channel, u16 address, u8 *buffer) {
    s32 ret;
    u8 status;
    s32 i;
    u8 *ptr;
    u32 crc;
    s32 retry;

    retry = 2;
    __osSiGetAccess();
    do {
        ptr = D_8009E9A0;
        if (D_8009D2E0 != 0xC || channel != D_800981A0) {
            D_8009D2E0 = 0xC;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            *(s32 *)(D_8009E9A0 + 0x3C) = 1;
            ptr[0] = 0xFF;
            ptr[1] = 7;
            ptr[2] = 1;
            ptr[3] = 0xC;
            ptr[0xA] = 0xFF;
            ptr[0xB] = 0xFE;
        } else {
            ptr = D_8009E9A0 + channel;
        }
        ptr[4] = address >> 3;
        ptr[5] = __osContAddressCrc(address) | (address << 5);
        bcopy(buffer, ptr + 6, 4);
        __osSiRawStartDma(1, D_8009E9A0);
        crc = __osVoiceContDataCrc(buffer, 4) & 0xFF;
        osRecvMesg(mq, 0, 1);
        __osSiRawStartDma(0, D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        ret = (ptr[2] & 0xC0) >> 4;
        if (ret == 0) {
            if ((ptr[0xA] ^ crc) != 0) { /* xor form: steers beql operand order */
                ret = __osVoiceGetStatus(mq, channel, &status);
                if (ret != 0) {
                    break;
                }
                ret = 4;
            }
        } else {
            ret = 1;
        }
    } while (ret == 4 && retry-- >= 0);
    __osSiRelAccess();
    return ret;
}
