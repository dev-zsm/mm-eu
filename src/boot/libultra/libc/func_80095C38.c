// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"

u64 __d_to_ull(f64 x) {
    return (u64)x;
}
