#include "types.h"

extern void Environment_LerpRGB8(u8 *a0, s32 a1, f32 a2, u8 *a3);

void Environment_LerpFogColor(u8 *play, s32 a1, f32 t) {
    Environment_LerpRGB8(play + 0x170D7, a1, t, play + 0x170A2);
}
