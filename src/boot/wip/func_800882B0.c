// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
} Func800882B0Struct;

s32 __osVoiceGetStatus(s32, s32, u8 *, void *);
s32 __osVoiceCheckResult(void *, u8 *);
void bzero(void *, s32, s32, u8 *);
s32 __osVoiceContWrite20(s32, s32, s32, void *);

s32 osVoiceSetWord(Func800882B0Struct *arg0, u8 *arg1) {
    u8 sp4B;
    u8 sp34[0x14];
    u8 sp20[0x14];
    s32 sp50;
    s32 n;
    s32 i;
    s32 r;
    u8 *dst;
    u8 *src;
    u8 tmp;

    r = __osVoiceGetStatus(arg0->unk0, arg0->unk4, &sp4B, arg0);
    if (r != 0) {
        return r;
    }
    if (sp4B & 2) {
        return 0xF;
    }

    n = 0;
    src = arg1;
    if (*src != 0) {
        do {
            n += 2;
            src += 2;
        } while (*src != 0);
    }
    sp50 = n;

    bzero(sp20, 0x28, n, arg1);

    i = 0;
    if (sp50 > 0) {
        dst = sp34 + 0x13 - n;
        src = arg1;
        do {
            i += 2;
            *dst = src[0];
            tmp = src[1];
            dst += 2;
            src += 2;
            dst[-3] = tmp;
        } while (i < sp50);
    }
    *(sp34 + 0x0E - i) = 3;

    if (sp50 >= 0xF) {
        r = __osVoiceContWrite20(arg0->unk0, arg0->unk4, 0, sp20);
        if (r != 0) {
            return r;
        }
    }
    r = __osVoiceContWrite20(arg0->unk0, arg0->unk4, 0, sp34);
    if (r != 0) {
        return r;
    }
    r = __osVoiceCheckResult(arg0, &sp4B);
    if (r != 0) {
        if (r & 0x100) {
            return 0xD;
        } else if (r & 0x200) {
            return 0xE;
        } else if (r & 0xFF00) {
            return 5;
        }
    }
    return r;
}
