// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    s32 mq;
    s32 channel;
    s32 mode;
} OSVoiceHandle;

extern s32 __osVoiceGetStatus();
extern s32 __osVoiceContWrite4();
extern s32 __osVoiceCheckResult();

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
        return 15;
    }
    if (hd->mode == 0) {
        return 5;
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
                    errorCode = 5;
                }
            } else {
                hd->mode = 0;
            }
            i++;
        } while (errorCode == 15 && i < 20);
    }
    if (i >= 20) {
    }
    return errorCode;
}
