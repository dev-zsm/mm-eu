// FLAGS: -O1 -g0 -mips2
#include "types.h"

void func_800958E0(f32 *src, u32 *dst) {
    u32 *end = dst + 8;
    do {
        s32 hi = src[0] * 65536.0f;
        s32 lo = src[1] * 65536.0f;
        src += 2;
        dst++;
        dst[-1] = ((u32)hi & 0xFFFF0000) | ((u32)lo >> 16);
        dst[7] = ((u32)hi << 16) | ((u32)lo & 0xFFFF);
    } while (dst != end);
}
