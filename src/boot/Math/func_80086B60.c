// FLAGS: -O2 -g0
#include "libm.h"

f32 Math_FAtanF(f32 x) {
    if (D_8009D0E0 == 0) {
        return Math_FAtanTaylorF(x);
    }
    return Math_FAtanContFracF(x);
}
