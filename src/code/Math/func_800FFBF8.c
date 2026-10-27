#include "types.h"

void Math_ApproachF(f32 *pValue, f32 target, f32 fraction, f32 step) {
    f32 delta;

    if (target != *pValue) {
        delta = (target - *pValue) * fraction;
        if (delta > step) {
            delta = step;
        } else if (delta < -step) {
            delta = -step;
        }
        *pValue += delta;
    }
}
