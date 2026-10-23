// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Thing {
    void *ptr;
    s32 size;
    u8 pad8[4];
    u8 flags;
} Thing;

s32 __osVoiceGetStatus(void *a, s32 b, void *c);
s32 __osVoiceContRead2(void *a, s32 b, s32 c, u8 *d);

s32 __osVoiceCheckResult(Thing *hd, u8 *status) {
    s32 ret;
    u8 buf[2];

    ret = __osVoiceGetStatus(hd->ptr, hd->size, status);
    if (ret == 0) {
        if (*status & 1) {
            ret = 0xF;
        } else {
            ret = __osVoiceContRead2(hd->ptr, hd->size, 0, buf);
            if (ret == 0) {
                hd->flags = buf[0] & 7;
                if (buf[0] & 0x40) {
                    ret = 0xF;
                } else {
                    ret = (u16)(buf[1] << 8);
                }
            }
        }
    }
    return ret;
}
