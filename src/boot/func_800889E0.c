// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"

u64 __ull_rshift(u64 x, u64 s) {
    return x >> s;
}
