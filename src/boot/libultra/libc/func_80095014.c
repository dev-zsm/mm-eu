// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "libultra_libc.h"

lldiv_t lldiv(s64 num, s64 den) {
    lldiv_t r;

    r.quot = __ll_div(num, den);
    r.rem = num - __ll_mul(den, r.quot);
    if (r.quot < 0) {
        if (r.rem > 0) {
            r.quot += 1;
            r.rem -= den;
        }
    }
    return r;
}
