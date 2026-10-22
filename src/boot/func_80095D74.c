// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"

f64 __ll_to_d(s64 x) {
    return (f64)x;
}
