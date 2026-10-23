// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 mq;
    s32 channel;
    s32 mode;
} VoiceHandle;

s32 __osVoiceGetStatus(s32 mq, s32 channel, u8 *status);
s32 __osVoiceContWrite4(s32 mq, s32 channel, s32 address, u8 *buffer);
s32 __osVoiceCheckResult(VoiceHandle *hd, u8 *status);

s32 osVoiceStopReadData(VoiceHandle *hd) {
    s32 errorCode;
    s32 i;
    u8 status;
    u32 data;

    errorCode = __osVoiceGetStatus(hd->mq, hd->channel, &status);
    if (errorCode != 0) {
        return errorCode;
    }
    if (status & 2) {
        return 0xF;
    }
    if (hd->mode == 0) {
        return 5;
    }
    data = 0x700;
    errorCode = __osVoiceContWrite4(hd->mq, hd->channel, 0, (u8 *)&data);
    if (errorCode == 0) {
        for (i = 0; i < 20; i++) {
            errorCode = __osVoiceCheckResult(hd, &status);
            if (errorCode & 0xFF00) {
                if ((errorCode & 7) == 0 || (errorCode & 7) == 7) {
                    errorCode = 0;
                    hd->mode = 0;
                } else {
                    errorCode = 5;
                }
            } else {
                hd->mode = 0;
            }
            if (errorCode != 0xF) {
                break;
            }
        }
    }
    return errorCode;
}
