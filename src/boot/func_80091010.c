// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

void __osSiGetAccess(void);
void __osSiRelAccess(void);
s32 osRecvMesg(void *mq, void *msg, s32 flag);
s32 __osSiRawStartDma(s32 dir, void *pifRam);
u8 __osContAddressCrc(u16 addr);
u8 __osVoiceContDataCrc(u8 *data, s32 size);
s32 __osVoiceGetStatus(void *mq, s32 channel, u8 *status);
void bcopy(void *src, void *dst, s32 n);

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern u8 D_8009E9A0[];

s32 __osVoiceContWrite20(void *mq, s32 channel, u16 address, u8 *buffer) {
    s32 ret;
    u8 status;
    s32 i;
    u8 *ptr;
    u8 crc;
    s32 retry = 2;

    __osSiGetAccess();
    do {
        ptr = D_8009E9A0;
        if (D_8009D2E0 != 0xA || channel != D_800981A0) {
            D_8009D2E0 = 0xA;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            *(s32 *)(D_8009E9A0 + 0x3C) = 1;
            ptr[0] = 0xFF;
            ptr[1] = 0x17;
            ptr[2] = 1;
            ptr[3] = 0xA;
            ptr[0x1A] = 0xFF;
            ptr[0x1B] = 0xFE;
        } else {
            ptr = D_8009E9A0 + channel;
        }
        ptr[4] = address >> 3;
        ptr[5] = __osContAddressCrc(address) | (address << 5);
        bcopy(buffer, ptr + 6, 0x14);
        __osSiRawStartDma(1, D_8009E9A0);
        crc = __osVoiceContDataCrc(buffer, 0x14);
        osRecvMesg(mq, NULL, 1);
        __osSiRawStartDma(0, D_8009E9A0);
        osRecvMesg(mq, NULL, 1);
        ret = (ptr[2] & 0xC0) >> 4;
        if (ret == 0) {
            /* xor form gives the ROM operand order of the compare */
            if (crc ^ ptr[0x1A]) {
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
