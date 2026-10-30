// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_voice.h"

s32 __osVoiceContWrite20(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer) {
    s32 ret;
    u8 status;
    s32 i;
    u8 *ptr;
    u8 crc;
    s32 retry = 2;

    __osSiGetAccess();
    do {
        ptr = (u8 *)&D_8009E9A0;
        if (D_8009D2E0 != CONT_CMD_WRITE20_VOICE || channel != D_800981A0) {
            D_8009D2E0 = CONT_CMD_WRITE20_VOICE;
            D_800981A0 = channel;
            i = 0;
            while (i < channel) {
                *ptr++ = 0;
                i++;
            }
            D_8009E9A0.pifstatus = 1;
            ptr[0] = 0xFF;
            ptr[1] = 0x17;
            ptr[2] = 1;
            ptr[3] = CONT_CMD_WRITE20_VOICE;
            ptr[0x1A] = 0xFF;
            ptr[0x1B] = CONT_CMD_END;
        } else {
            ptr = (u8 *)&D_8009E9A0 + channel;
        }
        ptr[4] = address >> 3;
        ptr[5] = __osContAddressCrc(address) | (address << 5);
        bcopy(buffer, ptr + 6, 0x14);
        __osSiRawStartDma(OS_WRITE, &D_8009E9A0);
        crc = __osVoiceContDataCrc(buffer, 0x14);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        __osSiRawStartDma(OS_READ, &D_8009E9A0);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        ret = (ptr[2] & 0xC0) >> 4;
        if (ret == 0) {
            /* xor form gives the ROM operand order of the compare */
            if (crc ^ ptr[0x1A]) {
                ret = __osVoiceGetStatus(mq, channel, &status);
                if (ret != 0) {
                    break;
                }
                ret = PFS_ERR_CONTRFAIL;
            }
        } else {
            ret = PFS_ERR_NOPACK;
        }
    } while (ret == PFS_ERR_CONTRFAIL && retry-- >= 0);
    __osSiRelAccess();
    return ret;
}
