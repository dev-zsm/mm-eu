#include "types.h"

void BgCheck_SetSubdivisionDimension(f32 min, s32 subdivLen, f32 *max, f32 *subdivAmount, f32 *inv) {
    float new_var;
    f32 n;
    new_var = (*max) - min;
    n = ((s32) (new_var / ((f32) subdivLen))) + 1;
    *subdivAmount = n;
    if (n < 150.0f) {
        *subdivAmount = 150.0f;
    } else {
        *subdivAmount = *subdivAmount;
    }
    *inv = 1.0f / (*subdivAmount);
    *max = ((*subdivAmount) * ((f32) subdivLen)) + min;
}
