// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"

void *func_800879D0(void *dst, const void *src, u32 n) {
    return (char *)memcpy(dst, src, n) + n;
}
