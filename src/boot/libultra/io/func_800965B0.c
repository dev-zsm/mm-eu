// FLAGS: -O2 -g0 -mips2
#include "os_voice.h"

s32 osVoiceStartReadData(OSVoiceHandle *hd) {
    s32 errorCode;
    u8 status;
    u32 data;
    s32 ret;

    errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
    if (errorCode != 0) {
        return errorCode;
    }
    if (status & 2) {
        return CONT_ERR_VOICE_NO_RESPONSE;
    }
    if (hd->mode != 0) {
        return PFS_ERR_INVALID;
    }
    data = 0x05000000;
    ret = __osVoiceContWrite4(hd->mq, hd->channel, 0, (u8 *)&data);
    if (ret == 0) {
        ret = __osVoiceCheckResult(hd, &status);
        if (ret & 0xFF00) {
            ret = PFS_ERR_INVALID;
        } else {
            hd->mode = 1;
        }
    }
    return ret;
}
