// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s64 quot;
    s64 rem;
} DivResult64;

s64 __ll_div(s64 num, s64 den);
s64 __ll_mul(s64 den, s64 quot);
DivResult64 lldiv(s64 num, s64 den) {
    DivResult64 r;

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
