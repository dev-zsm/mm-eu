// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

u64 __f_to_ull(f32 x) {
    return (u64)x;
}
