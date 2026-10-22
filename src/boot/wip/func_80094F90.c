// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 quot;
    s32 rem;
} DivResult;

DivResult ldiv(s32 num, s32 den) {
    DivResult r;

    r.quot = num / den;
    r.rem = num - den * r.quot;
    if (r.quot < 0 && r.rem > 0) {
        r.quot += 1;
        r.rem -= den;
    }
    return r;
}
