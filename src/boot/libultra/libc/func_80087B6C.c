// FLAGS: -O2 -g0 -mips2
#include "libultra_libc.h"

void nsleep(u32 ns) {
    csleep((u64)ns * 3 / 64);
}
