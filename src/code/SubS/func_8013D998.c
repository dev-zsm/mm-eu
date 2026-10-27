#include "types.h"

s32 SubS_AngleDiffLessEqual(s16 angleA, s16 maxDiff, s16 angleB) {
    s16 diff = angleB - angleA;
    s32 absDiff;
    s32 result;

    if (diff < 0) {
        absDiff = -diff;
    } else {
        absDiff = diff;
    }
    if (absDiff <= maxDiff) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
