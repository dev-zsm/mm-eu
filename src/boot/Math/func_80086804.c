// FLAGS: -O2 -g0
#include "sdk/libm.h"

f32 Math_FFloorF(f32 x) {
    return floorf(x);
}
