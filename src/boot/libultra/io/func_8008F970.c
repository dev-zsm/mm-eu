// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_voice.h"

s32 __osVoiceContRead36(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer) {
    s32 ret = 0;
    u8 status;
    s32 i;
    u8 *ptr;
    s32 retry = 2;

    __osSiGetAccess();
    do {
        ptr = (u8 *)&D_8009E9A0;
        if (D_8009D2E0 != CONT_CMD_READ36_VOICE || channel != D_800981A0) {
            D_8009D2E0 = CONT_CMD_READ36_VOICE;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            D_8009E9A0.pifstatus = 1;
            ((__OSVoiceRead36Format *)ptr)->dummy = 0xFF;
            ((__OSVoiceRead36Format *)ptr)->txsize = 3;
            ((__OSVoiceRead36Format *)ptr)->rxsize = 0x25;
            ((__OSVoiceRead36Format *)ptr)->cmd = CONT_CMD_READ36_VOICE;
            ((__OSVoiceRead36Format *)ptr)->datacrc = 0xFF;
            ((__OSVoiceRead36Format *)ptr)->end = CONT_CMD_END;
        } else {
            ptr = (u8 *)&D_8009E9A0 + channel;
        }
        ((__OSVoiceRead36Format *)ptr)->addrh = address >> 3;
        ((__OSVoiceRead36Format *)ptr)->addrl = __osContAddressCrc(address) | (address << 5);
        __osSiRawStartDma(OS_WRITE, &D_8009E9A0);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        __osSiRawStartDma(OS_READ, &D_8009E9A0);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        ret = (((__OSVoiceRead36Format *)ptr)->rxsize & 0xC0) >> 4;
        if (ret == 0) {
            if (__osVoiceContDataCrc(ptr + 6, 36) != ((__OSVoiceRead36Format *)ptr)->datacrc) {
                ret = __osVoiceGetStatus(mq, channel, &status);
                if (ret != 0) {
                    break;
                }
                ret = PFS_ERR_CONTRFAIL;
            } else {
                bcopy(ptr + 6, buffer, 36);
            }
        } else {
            ret = PFS_ERR_NOPACK;
        }
    } while (ret == PFS_ERR_CONTRFAIL && !(retry-- < 0));
    __osSiRelAccess();
    return ret;
}
