// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

s64 __d_to_ll(f64 x) {
    return (s64)x;
}
