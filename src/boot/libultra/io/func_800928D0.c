// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_voice.h"

s32 __osVoiceGetStatus(OSMesgQueue *mq, s32 channel, u8 *status) {
    __OSVoiceStatusFormat fmt;
    s32 ret;
    s32 i;
    u8 *ptr;
    s32 retry;
    ret = 0;
    ptr = (u8 *)&D_8009D2A0;
    retry = 2;

    __osSiGetAccess();
    do {
        if (ret != PFS_ERR_CONTRFAIL) {
            D_8009D2A0.pifstatus = 1;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            ((__OSVoiceStatusFormat *)ptr)->dummy = 1;
            ((__OSVoiceStatusFormat *)ptr)->txsize = 3;
            ((__OSVoiceStatusFormat *)ptr)->rxsize = 0;
            ptr += 6;
            *ptr = CONT_CMD_END;
            D_8009D2E0 = CONT_CMD_END;
            __osSiRawStartDma(OS_WRITE, &D_8009D2A0);
            osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        }
        __osSiRawStartDma(OS_READ, &D_8009D2A0);
        ptr = (u8 *)&D_8009D2A0 + channel;
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        fmt = *(__OSVoiceStatusFormat *)ptr;
        ret = (u8)((fmt.txsize & 0xC0) >> 4);
        *status = fmt.data;
        if (ret == 0) {
            if (fmt.cmd == 0 && fmt.status == 1) {
                if (fmt.data & 4) {
                    ret = PFS_ERR_CONTRFAIL;
                }
            } else {
                ret = PFS_ERR_DEVICE;
            }
        } else {
            ret = (ret & 8) ? PFS_ERR_NOPACK : PFS_ERR_CONTRFAIL;
        }
    } while (ret == PFS_ERR_CONTRFAIL && retry-- >= 0);
    __osSiRelAccess();
    return ret;
}
