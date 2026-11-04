// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fcurve_data.h"

f32 Curve_Interpolate(f32 x, CurveInterpKnot* knots, s32 knotCount) {
    
    if (x <= knots[0].abscissa) {
        return knots[0].ordinate;
    } else if (x >= knots[knotCount - 1].abscissa) {
        return knots[knotCount - 1].ordinate;
    } else {
        s32 cur;

        for (cur = 0;; cur++) {
            s32 next = cur + 1;

            
            if (x < knots[next].abscissa) {
                if (knots[cur].flags & FCURVE_INTERP_NONE) {
                    
                    return knots[cur].ordinate;
                } else if (knots[cur].flags & FCURVE_INTERP_LINEAR) {
                    
                    return knots[cur].ordinate +
                           ((x - (f32)knots[cur].abscissa) / ((f32)knots[next].abscissa - (f32)knots[cur].abscissa)) *
                               (knots[next].ordinate - knots[cur].ordinate);
                } else {
                    
                    f32 diff = (f32)knots[next].abscissa - (f32)knots[cur].abscissa;
                    f32 t = (x - (f32)knots[cur].abscissa) / ((f32)knots[next].abscissa - (f32)knots[cur].abscissa);

                    return Curve_CubicHermiteSpline(t, diff * (1.0f / 30.0f), knots[cur].ordinate, knots[next].ordinate,
                                                    knots[cur].rightGradient, knots[next].leftGradient);
                }
            }
        }
    }
}
