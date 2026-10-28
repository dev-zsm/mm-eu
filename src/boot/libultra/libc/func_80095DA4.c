// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"

f64 __ull_to_d(u64 arg0) {
    return (f64)arg0;
}
