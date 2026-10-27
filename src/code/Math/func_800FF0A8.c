#include "types.h"

s32 Math_StepUntilF(f32 *pValue, f32 limit, f32 step) {
    f32 prev = *pValue;

    *pValue += step;
    if ((*pValue - limit) * (prev - limit) <= 0.0f) {
        *pValue = limit;
        return 1;
    }
    return 0;
}
