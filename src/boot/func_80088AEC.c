// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"

s64 __ll_div(s64 a, s64 b) {
    return a / b;
}
