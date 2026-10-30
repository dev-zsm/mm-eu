// FLAGS: -O2 -g0 -mips2
#include "os_voice.h"

s32 osVoiceClearDictionary(OSVoiceHandle *hd, u8 numWords) {
    s32 err;
    u8 buf[8];
    s32 r;

    err = __osVoiceGetStatus(hd->mq, hd->channel, &buf[7]);
    if (err != 0) {
        return err;
    }
    if (buf[7] & 0x2) {
        return CONT_ERR_VOICE_NO_RESPONSE;
    }
    *(u32 *)buf = 0x02000000;
    buf[2] = numWords;
    err = __osVoiceContWrite4(hd->mq, hd->channel, 0, buf);
    if (err != 0) {
        return err;
    }
    err = __osVoiceCheckResult(hd, &buf[7]);
    r = err;
    if (err & 0xFF00) {
        r = PFS_ERR_INVALID;
    }
    return r;
}
