// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"

void func_80080180(u32 *dst, u32 size, u32 value) {
    while (size > 0) {
        size -= 4;
        *dst++ = value;
    }
}
