// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_8009E9A0[];
s32 __osSiGetAccess(void);
void __osSiRelAccess(void);
s32 __osSiRawStartDma(s32, u8 *);
void osRecvMesg(s32, s32, s32);

s32 __osContChannelReset(s32 mq, s32 channels) {
    s32 i;
    s32 ret;
    u8 *ptr;

    ptr = D_8009E9A0;
    __osSiGetAccess();
    *(s32 *)&D_8009E9A0[0x3C] = 1;
    for (i = 0; i < channels; i++) {
        *ptr = 0;
        ptr++;
    }
    *ptr = 0xFD;
    ptr++;
    *ptr = 0xFE;
    __osSiRawStartDma(1, D_8009E9A0);
    osRecvMesg(mq, 0, 1);
    ret = __osSiRawStartDma(0, D_8009E9A0);
    osRecvMesg(mq, 0, 1);
    __osSiRelAccess();
    return ret;
}
