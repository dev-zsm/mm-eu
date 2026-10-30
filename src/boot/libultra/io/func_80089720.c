// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_voice.h"

s32 __osVoiceCheckResult(OSVoiceHandle *hd, u8 *status) {
    s32 ret;
    u8 buf[2];

    ret = __osVoiceGetStatus(hd->mq, hd->channel, status);
    if (ret == 0) {
        if (*status & 1) {
            ret = CONT_ERR_VOICE_NO_RESPONSE;
        } else {
            ret = __osVoiceContRead2(hd->mq, hd->channel, 0, buf);
            if (ret == 0) {
                hd->cmdStatus = buf[0] & 7;
                if (buf[0] & 0x40) {
                    ret = CONT_ERR_VOICE_NO_RESPONSE;
                } else {
                    ret = buf[1] << 8;
                }
            }
        }
    }
    return ret;
}
