#include "types.h"

void Math_ApproachZeroF(f32 *pValue, f32 scale, f32 maxStep) {
    f32 step = *pValue * scale;

    if (maxStep < step) {
        step = maxStep;
    } else if (step < -maxStep) {
        step = -maxStep;
    }
    *pValue -= step;
}
