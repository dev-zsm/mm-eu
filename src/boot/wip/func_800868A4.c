// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "types.h"
// best attempt: 3 instr differ (nx lands in $f18 instead of $f16). coeffs is the function-static of the original source, so the object keeps its own .rodata.
f32 Math_FAtanTaylorQF(f32 x) {
    static const f32 coeffs[] = { -0.33333334f, 0.2f, -0.14285715f, 0.11111111f, -0.09090909f, 0.07692308f, -0.06666667f, 0.05882353f, 0.0f };
    f32 poly = x;
    f32 sq = x * x;
    f32 exp = x * sq;
    f32 term;
    f32 nx;
    f32 *p = coeffs;

    while (1) {
        term = exp * *p++;
        nx = poly + term;
        if (poly == nx) {
            break;
        }
        exp *= sq;
        poly = nx;
    }
    return poly;
}
