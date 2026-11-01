// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
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
s32 __osVoiceGetStatus(s32 mq, s32 channel, u8 *status);

s32 __osVoiceSetADConverter(s32 mq, s32 channel, u8 data) {
    s32 ret;
    u8 status;
    u8 *ptr;
    s32 i;
    s32 retry = 2;

    __osSiGetAccess();
    do {
        ptr = (u8 *)&D_8009E9A0;
        if (D_8009D2E0 != 0xD || D_800981A0 != channel) {
            D_8009D2E0 = 0xD;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            ptr[0] = 3;
            ptr[1] = D_8009E9A0.pifstatus = 1;
            ptr[2] = 0xD;
            ptr[5] = 0;
            ptr[6] = 0xFE;
        } else {
            ptr += channel;
        }
        ptr[3] = data;
        ptr[4] = __osContAddressCrc(data * 8);
        __osSiRawStartDma(1, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        __osSiRawStartDma(0, &D_8009E9A0);
        osRecvMesg(mq, 0, 1);
        ret = (ptr[1] & 0xC0) >> 4;
        if (ret == 0) {
            if (ptr[5] & 1) {
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
