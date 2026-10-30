// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_voice.h"

s32 osVoiceStopReadData(OSVoiceHandle *hd) {
    s32 errorCode;
    s32 i;
    u8 status;
    u8 data[4];
    s32 pad[2];

    errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
    if (errorCode != 0) {
        return errorCode;
    }
    if (status & 2) {
        return CONT_ERR_VOICE_NO_RESPONSE;
    }
    if (hd->mode == 0) {
        return PFS_ERR_INVALID;
    }
    *(u32 *)data = 0x700;
    errorCode = __osVoiceContWrite4(hd->mq, hd->channel, 0, data);
    if (errorCode == 0) {
        i = 0;
        do {
            errorCode = __osVoiceCheckResult(hd, &status);
            if (errorCode & 0xFF00) {
                errorCode &= 7;
                // matching: ^ 0 gives the ROM operand order
                if (errorCode == 0 || (errorCode ^ 0) == 7) {
                    errorCode = 0;
                    hd->mode = 0;
                } else {
                    errorCode = PFS_ERR_INVALID;
                }
            } else {
                hd->mode = 0;
            }
            i++;
        } while (errorCode == CONT_ERR_VOICE_NO_RESPONSE && i < 20);
    }
    if (i >= 20) {
    }
    return errorCode;
}
