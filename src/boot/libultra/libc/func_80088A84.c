// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

u64 __ll_lshift(u64 x, u64 shift) {
    return x << shift;
}
