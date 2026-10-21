// FLAGS: -O2 -g0
#include "types.h"

void func_80086180(s16 *a0, f32 *a1) {
    f32 *src;
    s16 *dst;
    s32 i;
    s32 v;
    f32 cur;

    src = a1;
    dst = a0;
    i = 1;
    cur = src[0] * 65536.0f;
    do {
        v = (s32)cur;
        i++;
        src += 4;
        dst += 4;
        dst[-4] = v >> 16;
        dst[12] = v;
        v = (s32)(src[-3] * 65536.0f);
        dst[-3] = v >> 16;
        dst[13] = v;
        v = (s32)(src[-2] * 65536.0f);
        dst[-2] = v >> 16;
        dst[14] = v;
        v = (s32)(src[-1] * 65536.0f);
        dst[-1] = v >> 16;
        dst[15] = v;
        cur = src[0] * 65536.0f;
    } while (i != 4);
    v = (s32)cur;
    src += 4;
    dst += 4;
    dst[-4] = v >> 16;
    dst[12] = v;
    v = (s32)(src[-3] * 65536.0f);
    dst[-3] = v >> 16;
    dst[13] = v;
    v = (s32)(src[-2] * 65536.0f);
    dst[-2] = v >> 16;
    dst[14] = v;
    v = (s32)(src[-1] * 65536.0f);
    dst[-1] = v >> 16;
    dst[15] = v;
}
