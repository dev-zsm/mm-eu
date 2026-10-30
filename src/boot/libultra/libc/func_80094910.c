// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "printf.h"

/* Splits the double held in the first eight bytes of px into a mantissa in [0.5, 1) and a binary exponent; returns -1
   for a finite non-zero value, 0 for zero, 1 for infinity and 2 for a NaN. */
s16 _Ldunscale(s16 *pex, Pft *px) {
    u16 *ps = (u16 *)px;
    s16 xchar = (ps[0] & 0x7FF0) >> 4;

    if (xchar == 0x7FF) {
        *pex = 0;
        return (s16)((ps[0] & 0xF || ps[1] || ps[2] || ps[3]) ? 2 : 1);
    } else if (xchar > 0) {
        ps[0] = (ps[0] & 0x800F) | 0x3FF0;
        *pex = xchar - 0x3FE;
        return -1;
    } else if (xchar < 0) {
        return 2;
    }
    *pex = 0;
    return 0;
}
