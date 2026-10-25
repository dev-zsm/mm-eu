#include "types.h"

extern void Lights_PointSetInfo(void *lights, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius, s32 type);

void Lights_PointGlowSetInfo(void *lights, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius) {
    Lights_PointSetInfo(lights, x, y, z, r, g, b, radius, 2);
}
