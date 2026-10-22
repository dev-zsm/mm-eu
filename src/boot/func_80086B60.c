// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0E0;
f32 Math_FAtanTaylorF(f32 arg0);
f32 Math_FAtanContFracF(f32 arg0);

f32 Math_FAtanF(f32 arg0) {
    if (D_8009D0E0 == 0) {
        return Math_FAtanTaylorF(arg0);
    }
    return Math_FAtanContFracF(arg0);
}
