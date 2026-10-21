// FLAGS: -O2 -g0 -mips2
#include "types.h"

u32 func_80091240(u32 a) {
    u32 x;
    u32 v;
    u32 m;
    u32 s;
    u32 t;

    x = a & 0xFFFF;
    v = 0;
    m = 0x400;
    do {
        s = v << 1;
        if (x & m) {
            if (s & 0x20) {
                v = s ^ 0x14;
            } else {
                v = s + 1;
            }
        } else {
            v = s; if (s & 0x20) { t = s ^ 0x15; v = t; }
        }
        m >>= 1;
    } while (m != 0);

    s = v << 1;
    v = s;
    if (s & 0x20) v = s ^ 0x15;
    s = v << 1;
    v = s;
    if (s & 0x20) v = s ^ 0x15;
    s = v << 1;
    v = s;
    if (s & 0x20) v = s ^ 0x15;
    s = v << 1;
    v = s;
    if (s & 0x20) v = s ^ 0x15;
    s = v << 1;
    v = s;
    if (s & 0x20) v = s ^ 0x15;

    return v & 0x1F;
}
