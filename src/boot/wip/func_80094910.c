// FLAGS: -O2 -g0 -mips2
#include "types.h"

s16 _Ldunscale(s16 *pex, u16 *ps) {
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
