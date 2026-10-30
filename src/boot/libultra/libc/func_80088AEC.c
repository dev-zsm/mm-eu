// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

s64 __ll_div(s64 x, s64 y) {
    return x / y;
}
