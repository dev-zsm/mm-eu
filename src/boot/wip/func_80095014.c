// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s64 quot;
    s64 rem;
} DivResult64;

s64 func_80088AEC(s64 num, s64 den);
s64 func_80088B48(s64 den, s64 quot);
DivResult64 func_80095014(s64 num, s64 den) {
    DivResult64 r;

    r.quot = func_80088AEC(num, den);
    r.rem = num - func_80088B48(den, r.quot);
    if (r.quot < 0) {
        if (r.rem > 0) {
            r.quot += 1;
            r.rem -= den;
        }
    }
    return r;
}
