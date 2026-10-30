// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "libm.h"

/* Odd Taylor series of atan: x - x^3/3 + x^5/5 - ..., summed until a term no longer changes the result. */
f32 Math_FAtanTaylorQF(f32 x) {
    static const f32 coeffs[] = { -0.33333334f, 0.2f, -0.14285715f, 0.11111111f, -0.09090909f, 0.07692308f, -0.06666667f, 0.05882353f, 0.0f };
    f32 poly = x;
    f32 sq = x * x;
    f32 exp = x * sq;
    f32 term;
    const f32 *p = coeffs;

    while (1) {
        term = exp * *p++;
        if (poly + term == poly) {
            break;
        }
        poly += term;
        exp *= sq;
    }
    return poly;
}
