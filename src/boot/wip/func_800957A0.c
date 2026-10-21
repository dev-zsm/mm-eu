// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 func_800928D0(s32 a, s32 b, u8 *c);
void func_800897D0(u8 *buf, s32 size, s32 n, s32 odd);
s32 func_80091010(s32 a, s32 b, s32 c, u8 *buf);
s32 func_80089720(s32 *obj, u8 *p);

s32 func_800957A0(s32 *obj, u8 *src, s32 len) {
    u8 buf[0x14];
    u8 flag;
    s32 n;
    s32 i;
    s32 ret;
    s32 odd;
    u8 *d;

    ret = func_800928D0(obj[0], obj[1], &flag);
    if (ret != 0) {
        return ret;
    }
    if (flag & 2) {
        return 0xF;
    }
    odd = len & 1;
    n = len + odd;
    func_800897D0(buf, 0x14, n, odd);
    buf[0x12 - n] = 4;
    for (i = 0; i < n; i += 2) {
        buf[0x14 - n + i] = src[i];
        buf[0x14 - n + i + 1] = src[i + 1];
    }
    if (odd != 0) {
        buf[0x13] = 0;
    }
    ret = func_80091010(obj[0], obj[1], 0, buf);
    if (ret != 0) {
        return ret;
    }
    ret = func_80089720(obj, &flag);
    if (ret & 0xFF00) {
        return 5;
    }
    return ret;
}
