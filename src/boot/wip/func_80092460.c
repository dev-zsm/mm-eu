// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Struct80092460;

s32 __osVoiceGetStatus(s32, s32, u8 *);
s32 __osVoiceContWrite4(s32, s32, s32, s32 *);
s32 __osVoiceCheckResult(Struct80092460 *, u8 *);

s32 osVoiceStopReadData(Struct80092460 *arg0) {
    s32 data;
    u8 status;
    s32 i;
    s32 v;

    v = __osVoiceGetStatus(arg0->unk0, arg0->unk4, &status);
    if (v != 0) {
        return v;
    }
    if (status & 2) {
        return 0xF;
    }
    if (arg0->unk8 == 0) {
        return 5;
    }
    data = 0x700;
    v = __osVoiceContWrite4(arg0->unk0, arg0->unk4, 0, &data);
    if (v == 0) {
        i = 0;
        do {
            v = __osVoiceCheckResult(arg0, &status);
            if (v & 0xFF00) {
                if ((v & 7) == 0 || (v & 7) == 7) {
                    v = 0;
                    arg0->unk8 = 0;
                } else {
                    v = 5;
                }
            } else {
                arg0->unk8 = 0;
            }
            i++;
            if (v != 0xF) {
                break;
            }
        } while (i != 0x14);
    }
    return v;
}
