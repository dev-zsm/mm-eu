// FLAGS: -O1 -g0 -mips3 -32
#include "os_internal.h"

s64 func_80088C74(s64 x, s64 shift) {
    return x >> shift;
}
