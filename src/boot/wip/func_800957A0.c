// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} H;

s32 __osVoiceGetStatus(s32 a, s32 b, u8 *c);
void bzero(u8 *buf, s32 size);
s32 __osVoiceContWrite20(s32 a, s32 b, s32 c, u8 *buf);
s32 __osVoiceCheckResult(H *obj, u8 *p);

s32 osVoiceMaskDictionary(H *obj, u8 *src, s32 len) {
    u8 buf[0x14];
    u8 flag;
    s32 n;
    s32 i;
    s32 ret;
    s32 odd;

    ret = __osVoiceGetStatus(obj->unk0, obj->unk4, &flag);
    if (ret != 0) {
        return ret;
    }
    if (flag & 2) {
        return 0xF;
    }
    odd = len & 1;
    if (odd) {
        n = len + 1;
    } else {
        n = len;
    }
    bzero(buf, 0x14);
    buf[0x12 - n] = 4;
    for (i = 0; i < n; i += 2) {
        buf[0x14 - n + i] = src[i];
        buf[0x14 - n + i + 1] = src[i + 1];
    }
    if (odd) {
        buf[0x13] = 0;
    }
    ret = __osVoiceContWrite20(obj->unk0, obj->unk4, 0, buf);
    if (ret == 0) {
        ret = __osVoiceCheckResult(obj, &flag);
        if (ret & 0xFF00) {
            ret = 5;
        }
    }
    return ret;
}
