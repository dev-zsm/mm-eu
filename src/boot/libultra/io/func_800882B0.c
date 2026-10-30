// FLAGS: -O2 -g0 -mips2
#include "libc.h"
#include "os_voice.h"

s32 osVoiceSetWord(OSVoiceHandle *hd, u8 *word) {
    s32 errorCode;
    s32 n;
    s32 i;
    u8 status;
    u8 data[0x28];
    u8 *p;
    u8 *q;

    errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
    if (errorCode != 0) {
        return errorCode;
    }
    if (status & 2) {
        return CONT_ERR_VOICE_NO_RESPONSE;
    }
    n = 0;
    p = word;
    if (*p != 0) {
        do {
            n += 2;
            p += 2;
        } while (*p != 0);
    }
    bzero(data, 0x28);
    i = 0;
    if (n > 0) {
        p = &data[0x27 - n];
        q = word;
        do {
            i += 2;
            *p = q[0];
            p += 2;
            q += 2;
            p[-3] = q[-1];
        } while (i < n);
    }
    data[0x22 - i] = 3;
    if (n >= 0xF) {
        errorCode = __osVoiceContWrite20(hd->mq, hd->channel, 0, data);
        if (errorCode != 0) {
            return errorCode;
        }
    }
    errorCode = __osVoiceContWrite20(hd->mq, hd->channel, 0, &data[0x14]);
    if (errorCode != 0) {
        return errorCode;
    }
    errorCode = __osVoiceCheckResult(hd, &status);
    if (errorCode != 0) {
        if (errorCode & 0x100) {
            errorCode = CONT_ERR_VOICE_MEMORY;
        } else if (errorCode & 0x200) {
            errorCode = CONT_ERR_VOICE_WORD;
        } else if (errorCode & 0xFF00) {
            errorCode = PFS_ERR_INVALID;
        }
    }
    return errorCode;
}
