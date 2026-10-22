// FLAGS: -O2 -g0
#include "types.h"

s32 lround(f64 x) {
    return (s32)(x + 0.5);
}
