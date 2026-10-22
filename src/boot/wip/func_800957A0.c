// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 __osVoiceGetStatus(s32 a, s32 b, u8 *c);
void bzero(u8 *buf, s32 size, s32 n, s32 odd);
s32 __osVoiceContWrite20(s32 a, s32 b, s32 c, u8 *buf);
s32 __osVoiceCheckResult(s32 *obj, u8 *p);

s32 osVoiceMaskDictionary(s32 *obj, u8 *src, s32 len) {
    u8 buf[0x14];
    u8 flag;
    s32 n;
    s32 i;
    s32 ret;
    s32 odd;
    u8 *d;

    ret = __osVoiceGetStatus(obj[0], obj[1], &flag);
    if (ret != 0) {
        return ret;
    }
    if (flag & 2) {
        return 0xF;
    }
    odd = len & 1;
    n = len + odd;
    bzero(buf, 0x14, n, odd);
    buf[0x12 - n] = 4;
    for (i = 0; i < n; i += 2) {
        buf[0x14 - n + i] = src[i];
        buf[0x14 - n + i + 1] = src[i + 1];
    }
    if (odd != 0) {
        buf[0x13] = 0;
    }
    ret = __osVoiceContWrite20(obj[0], obj[1], 0, buf);
    if (ret != 0) {
        return ret;
    }
    ret = __osVoiceCheckResult(obj, &flag);
    if (ret & 0xFF00) {
        return 5;
    }
    return ret;
}
