// FLAGS: -O2 -g0
#include "libm.h"

/* acos(x) = pi/2 - asin(x) */
f32 Math_FAcosF(f32 x) {
    return D_8009939C - Math_FAsinF(x);
}
