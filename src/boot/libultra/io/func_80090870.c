// FLAGS: -O2 -g0 -mips2
#include "os_voice.h"

s32 osVoiceInit(OSMesgQueue *mq, OSVoiceHandle *hd, s32 channel) {
    s32 ret;
    s32 i; /* index loop (strength-reduced by IDO); also reserves the stack slot like the ROM */
    u8 status;
    u32 data;

    status = 0;
    hd->channel = channel;
    hd->mq = mq;
    hd->mode = 0;
    ret = __osVoiceGetStatus(mq, channel, &status);
    if (ret != 0) {
        return ret;
    }
    if (__osContChannelReset(mq, channel) != 0) {
        return PFS_ERR_CONTRFAIL;
    }
    for (i = 0; i < 5; i++) {
        ret = __osVoiceSetADConverter(mq, channel, D_80098190[i]);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osVoiceGetStatus(mq, channel, &status);
    if (ret != 0) {
        return ret;
    }
    if (status & 2) {
        return CONT_ERR_VOICE_NO_RESPONSE;
    }
    data = 0x100;
    ret = __osVoiceContWrite4(mq, channel, 0, (u8 *)&data);
    if (ret != 0) {
        return ret;
    }
    ret = __osVoiceCheckResult(hd, &status);
    if (ret & 0xFF00) {
        ret = PFS_ERR_INVALID;
    }
    return ret;
}
