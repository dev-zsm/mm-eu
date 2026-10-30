// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

f32 __ll_to_f(s64 x) {
    return (f32)x;
}
