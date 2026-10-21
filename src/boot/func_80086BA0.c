// FLAGS: -O2 -g0
#include "types.h"

extern f32 D_800976C4;   /* NaN result */
extern f32 D_8009938C;   /* +pi/2 (y > 0, x == 0) */
extern f32 D_80099390;   /* -pi/2 (y < 0, x == 0) */
extern f32 D_80099394;   /* pi, subtracted for x < 0, y < 0 */
extern f32 D_80099398;   /* pi, used for x < 0, y >= 0 */
f32 func_80086B60(f32 arg0);

/*
 * Single-precision atan2(y, x) (atan2f). Works on the quotient y/x through func_80086B60
 * (the arctangent core) and adds or subtracts pi by quadrant. Constants are inferred
 * from the branches, not checked against the ROM data.
 */
f32 func_80086BA0(f32 y, f32 x) {
    if (x == 0.0f) {
        if (y == 0.0f) {
            return 0.0f;
        }
        if (0.0f < y) {
            return D_8009938C;
        }
        if (y < 0.0f) {
            return D_80099390;
        }
        return D_800976C4;
    }
    if (0.0f <= x) {
        return func_80086B60(y / x);
    }
    if (y < 0.0f) {
        return func_80086B60(y / x) - D_80099394;
    }
    return D_80099398 - func_80086B60(-(y / x));
}
