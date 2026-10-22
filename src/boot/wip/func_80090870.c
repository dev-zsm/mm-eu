// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Func80090870Struct;

extern u8 D_80098190[];
extern u8 D_80098195[];
s32 __osVoiceGetStatus(s32, s32, s32, s32);
s32 __osContChannelReset(s32, s32);
s32 __osVoiceSetADConverter(s32, s32, s32);
s32 __osVoiceContWrite4(s32, s32, s32, s32 *);
s32 __osVoiceCheckResult(s32, s32);

s32 osVoiceInit(s32 arg0, Func80090870Struct *arg1, s32 arg2) {
    u8 sp37;
    s32 sp30;
    s32 ret;
    u8 *p;

    sp37 = 0;
    arg1->unk4 = arg2;
    arg1->unk0 = arg0;
    arg1->unk8 = 0;
    ret = __osVoiceGetStatus(arg0, arg2, (s32)&sp37, (s32)arg1);
    if (ret != 0) {
        return ret;
    }
    if (__osContChannelReset(arg0, arg2) != 0) {
        return 4;
    }
    p = D_80098190;
    do {
        ret = __osVoiceSetADConverter(arg0, arg2, *p);
        if (ret != 0) {
            return ret;
        }
        p++;
    } while (p != D_80098195);
    ret = __osVoiceGetStatus(arg0, arg2, (s32)&sp37, (s32)arg1);
    if (ret != 0) {
        return ret;
    }
    if (sp37 & 2) {
        return 0xF;
    }
    sp30 = 0x100;
    ret = __osVoiceContWrite4(arg0, arg2, 0, &sp30);
    if (ret != 0) {
        return ret;
    }
    ret = __osVoiceCheckResult((s32)arg1, (s32)&sp37);
    if (ret & 0xFF00) {
        return 5;
    }
    return ret;
}
