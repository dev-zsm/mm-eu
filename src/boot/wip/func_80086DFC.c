// FLAGS: -O2 -g0
#include "types.h"

s32 lroundf(f32 x) {
    return (s32)(x + 0.5f);
}
