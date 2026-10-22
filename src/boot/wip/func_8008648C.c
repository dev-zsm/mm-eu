// FLAGS: -O2 -g0
#include "types.h"

extern u32 func_80086350(s32 size);

u32 func_8008648C(u32 buf, u32 n, u32 size, void (*cb)(u32, s32, s32, s32, s32, s32, s32, s32, s32)) {
    u32 end;
    u32 p;

    if (buf == 0) {
        buf = func_80086350(n * size);
    }
    if (buf == 0 || cb == 0) {
        return buf;
    }
    p = buf;
    end = buf + n * size;
    while (p < end) {
        cb(p, 0, 0, 0, 0, 0, 0, 0, 0);
        p += size;
    }
    return buf;
}
