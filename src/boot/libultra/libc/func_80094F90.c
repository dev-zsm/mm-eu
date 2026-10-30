// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "libultra_libc.h"

ldiv_t ldiv(s32 num, s32 den) {
    ldiv_t r;

    r.quot = num / den;
    r.rem = num - den * r.quot;
    if (r.quot < 0 && r.rem > 0) {
        r.quot += 1;
        r.rem -= den;
    }
    return r;
}
