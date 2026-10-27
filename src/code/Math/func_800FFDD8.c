#include "types.h"

void Math_ApproachS(s16 *pValue, s16 target, s16 scale, s16 maxStep) {
    s16 diff = target - *pValue;

    diff = diff / scale;
    if (diff > maxStep) {
        *pValue += maxStep;
    } else if (diff < -maxStep) {
        *pValue -= maxStep;
    } else {
        *pValue += diff;
    }
}
