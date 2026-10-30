// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// matching: address bits are hoisted by the compiler; status copy order follows the ROM
#include "os_voice.h"

s32 __osVoiceContRead2(OSMesgQueue *mq, s32 channel, u16 address, u8 *buffer) {
    s32 ret;
    u8 status;
    u8 *ptr;
    s32 i;
    s32 retry = 2;

    __osSiGetAccess();
    do {
        ptr = (u8 *)&D_8009E9A0;
        if (D_8009D2E0 != CONT_CMD_READ2_VOICE || D_800981A0 != channel) {
            D_8009D2E0 = CONT_CMD_READ2_VOICE;
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
            ptr[3] = CONT_CMD_READ2_VOICE;
            ptr[8] = 0xFF;
            ptr[9] = CONT_CMD_END;
        } else {
            ptr += channel;
        }
        ptr[4] = address >> 3;
        ptr[5] = __osContAddressCrc(address) | (address << 5);
        __osSiRawStartDma(OS_WRITE, &D_8009E9A0);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        __osSiRawStartDma(OS_READ, &D_8009E9A0);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        ret = (ptr[2] & 0xC0) >> 4;
        if (ret == 0) {
            if (ptr[8] != __osVoiceContDataCrc(ptr + 6, 2)) {
                ret = __osVoiceGetStatus(mq, channel, &status);
                if (ret != 0) {
                    break;
                }
                ret = PFS_ERR_CONTRFAIL;
            } else {
                bcopy(ptr + 6, buffer, 2);
            }
        } else {
            ret = PFS_ERR_NOPACK;
        }
    } while (ret == PFS_ERR_CONTRFAIL && retry-- >= 0);
    __osSiRelAccess();
    return ret;
}
