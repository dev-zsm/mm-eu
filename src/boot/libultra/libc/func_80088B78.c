// FLAGS: -O1 -g0 -mips3 -32
#include "libultra_libc.h"

// matching: volatile divisor
void __ull_divremi(u64 *quot, u64 *rem, u64 x, volatile u16 y) {
    *quot = x / y;
    *rem = x % y;
}
