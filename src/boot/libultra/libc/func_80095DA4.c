// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

f64 __ull_to_d(u64 x) {
    return (f64)x;
}
