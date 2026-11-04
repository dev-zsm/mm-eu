// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_lib.h"

f32 Math_SmoothStepToF(f32* pValue, f32 target, f32 fraction, f32 step, f32 minStep) {
    f32 stepSize;

    if (*pValue != target) {
        stepSize = (target - *pValue) * fraction;

        if ((stepSize >= minStep) || (stepSize <= -minStep)) {
            if (stepSize > step) {
                stepSize = step;
            }

            if (stepSize < -step) {
                stepSize = -step;
            }

            *pValue += stepSize;
        } else {
            if (stepSize > 0) {
                if (stepSize < minStep) {
                    *pValue += minStep;

                    if (target < *pValue) {
                        *pValue = target;
                    }
                }
            } else {
                if (-minStep < stepSize) {
                    *pValue += -minStep;

                    if (*pValue < target) {
                        *pValue = target;
                    }
                }
            }
        }
    }

    return fabsf(target - *pValue);
}
