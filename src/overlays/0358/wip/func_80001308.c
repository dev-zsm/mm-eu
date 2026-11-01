// FLAGS: -O2 -g3 -mips2
#include "types.h"

f32 func_80001308(f32 a0, f32 a1, f32 a2, f32 *a3) {
    return -((a3[0] * a0) + (a1 * a3[1]) + (a2 * a3[2]));
}
