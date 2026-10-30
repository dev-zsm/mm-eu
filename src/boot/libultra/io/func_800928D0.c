// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 status;
    u8 data;
} VoiceFmt;

extern u8 D_8009D2A0[];
extern u8 D_8009D2E0;
void __osSiGetAccess(void);
void __osSiRelAccess(void);
void __osSiRawStartDma(s32 dir, void *buf);
void osRecvMesg(void *mq, void *msg, s32 flag);

s32 __osVoiceGetStatus(void *mq, s32 channel, u8 *status) {
    VoiceFmt fmt;
    s32 ret;
    s32 i;
    u8 *ptr;
    s32 retry;
    ret = 0;
    ptr = D_8009D2A0;
    retry = 2;

    __osSiGetAccess();
    do {
        if (ret != 4) {
            *(u32 *)(D_8009D2A0 + 0x3C) = 1;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            ((VoiceFmt *)ptr)->dummy = 1;
            ((VoiceFmt *)ptr)->txsize = 3;
            ((VoiceFmt *)ptr)->rxsize = 0;
            ptr += 6;
            *ptr = 0xFE;
            D_8009D2E0 = 0xFE;
            __osSiRawStartDma(1, D_8009D2A0);
            osRecvMesg(mq, 0, 1);
        }
        __osSiRawStartDma(0, D_8009D2A0);
        ptr = D_8009D2A0 + channel;
        osRecvMesg(mq, 0, 1);
        fmt = *(VoiceFmt *)ptr;
        ret = (u8)((fmt.txsize & 0xC0) >> 4);
        *status = fmt.data;
        if (ret == 0) {
            if (fmt.cmd == 0 && fmt.status == 1) {
                if (fmt.data & 4) {
                    ret = 4;
                }
            } else {
                ret = 0xB;
            }
        } else {
            ret = (ret & 8) ? 1 : 4;
        }
    } while (ret == 4 && retry-- >= 0);
    __osSiRelAccess();
    return ret;
}
