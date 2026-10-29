// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// matching: address bits are hoisted by the compiler; status copy order follows the ROM
#include "types.h"

typedef struct {
    u8 ramarray[0x3C];
    s32 pifstatus;
} PifRam;

extern s32 D_800981A0;
extern u8 D_8009D2E0;
extern PifRam D_8009E9A0;

void __osSiGetAccess(void);
void __osSiRelAccess(void);
void osRecvMesg(s32 mq, s32 msg, s32 flag);
s32 __osSiRawStartDma(s32 dir, void *data);
u8 __osContAddressCrc(u16 addr);
u8 __osVoiceContDataCrc(u8 *data, u32 n);
s32 __osVoiceGetStatus(s32 mq, s32 channel, u8 *status);
void bcopy(void *src, void *dst, u32 n);

s32 __osVoiceContRead2(s32 mq, s32 channel, u16 address, u8 *buffer) {
    s32 ret;
    u8 status;
    u8 *ptr;
    s32 i;
    s32 retry = 2;

    __osSiGetAccess();
    do {
        ptr = (u8 *)&D_8009E9A0;
        if (D_8009D2E0 != 0xB || D_800981A0 != channel) {
            D_8009D2E0 = 0xB;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            D_8009E9A0.pifstatus = 1;
            ptr[0] = 0xFF;
            ptr[1] = 3;
            ptr[2] = 3;
            ptr[3] = 0xB;
            ptr[8] = 0xFF;
            ptr[9] = 0xFE;
        } else {
            ptr += channel;
        }
        ptr[4] = address >> 3;
        ptr[5] = __osContAddressCrc(address) | (address << 5);
        __osSiRawStartDma(1, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        __osSiRawStartDma(0, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        ret = (ptr[2] & 0xC0) >> 4;
        if (ret == 0) {
            if (ptr[8] != __osVoiceContDataCrc(ptr + 6, 2)) {
                ret = __osVoiceGetStatus(mq, channel, &status);
                if (ret != 0) {
                    break;
                }
                ret = 4;
            } else {
                bcopy(ptr + 6, buffer, 2);
            }
        } else {
            ret = 1;
        }
    } while (ret == 4 && retry-- >= 0);
    __osSiRelAccess();
    return ret;
}
