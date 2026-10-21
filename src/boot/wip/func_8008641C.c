// FLAGS: -O2 -g0
#include "types.h"

void func_8008641C(u32 a0, s32 a1, s32 a2, void (*a3)(u32, s32)) {
    u32 end;
    u32 p = a0;

    end = a0;
    end += a1 * a2;
    if (p < end) {
        do {
            a3(p, 2);
            p += a2;
        } while (p < end);
    }
}
