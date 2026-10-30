// FLAGS: -O2 -g0 -mips2
#include "libc.h"
#include "os_voice.h"

s32 osVoiceMaskDictionary(OSVoiceHandle *hd, u8 *maskPattern, s32 size) {
    s32 i;
    s32 ret;
    s32 n;
    u8 flag;
    u8 buf[0x14];

    ret = __osVoiceGetStatus(hd->mq, hd->channel, &flag);
    if (ret != 0) {
        return ret;
    }
    if (flag & 2) {
        return CONT_ERR_VOICE_NO_RESPONSE;
    }
    if (size & 1) {
        n = size + 1;
    } else {
        n = size;
    }
    bzero(buf, 0x14);
    buf[0x12 - n] = 4;
    for (i = 0; i < n; i += 2) {
        buf[i + 0x14 - n] = maskPattern[i];
        buf[i + 0x14 - n + 1] = maskPattern[i + 1];
    }
    if (size & 1) {
        buf[0x13] = 0;
    }
    ret = __osVoiceContWrite20(hd->mq, hd->channel, 0, buf);
    if (ret == 0) {
        ret = __osVoiceCheckResult(hd, &flag);
        if (ret & 0xFF00) {
            ret = PFS_ERR_INVALID;
        }
    }
    return ret;
}
