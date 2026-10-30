// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

f32 __ull_to_f(u64 x) {
    return (f32)x;
}
