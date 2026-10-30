// FLAGS: -O1 -g0 -mips3 -32
#include "os_internal.h"

s64 func_80088BD8(s64 x, s64 y) {
    s64 r = x % y;

    if ((r < 0 && y > 0) || (r > 0 && y < 0)) {
        r += y;
    }
    return r;
}
