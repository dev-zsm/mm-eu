// FLAGS: -O2 -g0
#include "sdk/libultra_libc.h"

void sleep(u32 s) {
    csleep((u64)s * OS_CPU_COUNTER);
}
