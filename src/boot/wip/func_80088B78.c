// FLAGS: -O1 -g0 -mips3 -32
#include "types.h"

void func_80088B78(u64 *q, u64 *r, u64 x, s16 y) {
    *q = x / y;
    *r = x % y;
}
