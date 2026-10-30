// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

u64 __ull_div(u64 x, u64 y) {
    return x / y;
}
