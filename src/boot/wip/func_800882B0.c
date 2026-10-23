// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} H;

s32 __osVoiceGetStatus(s32, s32, u8 *);
s32 __osVoiceCheckResult(H *, u8 *);
void bzero(void *, s32);
s32 __osVoiceContWrite20(s32, s32, s32, u8 *);

s32 osVoiceSetWord(H *hd, u8 *word) {
    s32 errorCode;
    s32 n;
    s32 i;
    u8 *dst;
    u8 *p;
    u8 status;
    u8 buf2[0x14];
    u8 buf1[0x14];

    errorCode = __osVoiceGetStatus(hd->unk0, hd->unk4, &status);
    if (errorCode != 0) {
        return errorCode;
    }
    if (status & 2) {
        return 0xF;
    }
    n = 0;
    p = word;
    if (*p != 0) {
        do {
            n += 2;
            p += 2;
        } while (*p != 0);
    }
    bzero(buf1, 0x28);
    i = 0;
    if (n > 0) {
        dst = &buf2[0x13 - n];
        p = word;
        do {
            i += 2;
            *dst = p[0];
            dst += 2;
            p += 2;
            dst[-3] = p[-1];
        } while (i < n);
    }
    buf2[0xE - i] = 3;
    if (n >= 0xF) {
        errorCode = __osVoiceContWrite20(hd->unk0, hd->unk4, 0, buf1);
        if (errorCode != 0) {
            return errorCode;
        }
    }
    errorCode = __osVoiceContWrite20(hd->unk0, hd->unk4, 0, buf2);
    if (errorCode != 0) {
        return errorCode;
    }
    errorCode = __osVoiceCheckResult(hd, &status);
    if (errorCode != 0) {
        if (errorCode & 0x100) {
            errorCode = 0xD;
        } else if (errorCode & 0x200) {
            errorCode = 0xE;
        } else if (errorCode & 0xFF00) {
            errorCode = 5;
        }
    }
    return errorCode;
}
