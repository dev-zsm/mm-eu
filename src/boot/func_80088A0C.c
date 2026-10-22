// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"

u64 __ull_rem(u64 a, u64 b) {
    return a % b;
}
