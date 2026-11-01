// FLAGS: -O2 -g3 -mips2
#include "types.h"

// ROM loop is a non-unrolled countdown ending in bgtzl; this form emits plain bgtz.
f32 Math_PowF(f32 base, s32 exp) {
    f32 result = 1.0f;

    if (exp > 0) {
        do {
            result *= base;
        } while (--exp > 0);
    }
    return result;
}
