// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"

void *func_80085140(u32 rangeStart, u32 rangeEnd, u32 start, u32 end) {
    void *buf;

    buf = malloc_r(end - start);
    if (buf != NULL) {
        func_80085074(rangeStart, rangeEnd, start, end, buf);
    }
    return buf;
}
