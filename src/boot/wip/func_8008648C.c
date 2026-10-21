// FLAGS: -O2 -g0
#include "types.h"

extern u32 func_80086350(s32 size);

u32 func_8008648C(u32 a0, s32 a1, s32 a2, void (*a3)(u32, s32, s32, s32, s32, s32, s32, s32, s32)) {
    u32 end;
    u32 p;
    u32 buf;

    buf = a0;
    if (buf == 0) {
        buf = func_80086350(a1 * a2);
    }
    if (buf != 0 && a3 != NULL) {
        p = buf;
        end = buf + a1 * a2;
        if (buf < end) {
            do {
                a3(p, 0, 0, 0, 0, 0, 0, 0, 0);
                p += a2;
            } while (p < end);
        }
    }
    return buf;
}
