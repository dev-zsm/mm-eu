// FLAGS: -O2 -g3 -mips2
#include "os_internal.h"

s32 func_80096A50(const u8 *s1, const u8 *s2) {
    u8 a;
    u8 b;

    for (;;) {
        a = *s1++;
        b = *s2++;
        if (a != b) {
            return a - b;
        }
        if (!a) {
            return 0;
        }
    }
}
