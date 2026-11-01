// FLAGS: -O1 -g0 -mips3 -32
#include "sdk/libultra_libc.h"

s64 __f_to_ll(f32 x) {
    return (s64)x;
}
