#include "types.h"

extern void Color_RGB8_Lerp(u8 *from, u8 *to, f32 t, u8 *result);

void Environment_LerpRGB8(u8 *from, u8 *to, f32 t, s16 *diff) {
    u8 lerped[3];

    Color_RGB8_Lerp(from, to, t, lerped);
    diff[0] = lerped[0] - from[0];
    diff[1] = lerped[1] - from[1];
    diff[2] = lerped[2] - from[2];
}
