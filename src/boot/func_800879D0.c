// FLAGS: -O2 -g0 -mips2
#include "types.h"

void *memcpy(void *dst, void *src, u32 n);

s32 func_800879D0(void *dst, void *src, u32 n) {
    return (s32)memcpy(dst, src, n) + n;
}
