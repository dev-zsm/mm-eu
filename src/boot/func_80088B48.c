// FLAGS: -O2 -g0 -mips3 -32
#include "types.h"

s64 __ll_mul(s64 a, s64 b) {
    return a * b;
}
