// FLAGS: -O2 -g0
#include "libultra_libc.h"

void usleep(u32 us) {
    csleep((u64)us * 3000 / 64);
}
