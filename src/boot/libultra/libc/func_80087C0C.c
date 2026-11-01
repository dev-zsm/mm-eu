// FLAGS: -O2 -g0
#include "sdk/libultra_libc.h"

void msleep(u32 ms) {
    csleep((u64)ms * OS_CPU_COUNTER / 1000);
}
