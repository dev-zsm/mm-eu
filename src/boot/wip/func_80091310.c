// FLAGS: -O2 -g0 -mips2
#include "types.h"

u8 func_80091310(u8 *p) {
    u32 v;
    u32 c;
    u32 m;
    u32 s;
    u32 n;

    v = 0;
    for (n = 0x20; n != 0; n--) {
        c = *p;
        m = 0x80;
        do {
            s = v << 1;
            if (c & m) {
                if (s & 0x100) {
                    v = s ^ 0x84;
                } else {
                    v = s + 1;
                }
            } else {
                v = s;
                if (s & 0x100) {
                    v = s ^ 0x85;
                }
            }
            m >>= 1;
        } while (m != 0);
        p++;
    }

    s = v << 1;
    for (n = 0; n != 8; n++) { if (s & 0x100) { v = s ^ 0x85; } else { v = s; } s = v << 1; }

    return v & 0xFF;
}
