// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    u8 pad0[2];
    s8 unk2;
    s8 unk3;
    u8 pad4[0x10];
    s8 unk14;
    s8 unk15;
} Input;

float sqrtf(float);
#pragma intrinsic (sqrtf)
s16 Math_Atan2S_XY(f32, f32);

void Lib_GetControlStickData(f32 *mag, s16 *angle, Input *in) {
    f32 x = in->unk14;
    f32 y = in->unk15;
    f32 m = sqrtf(x * x + y * y);
    f32 a, b;

    if (m > 60.0f) {
        *mag = 60.0f;
    } else {
        *mag = m;
    }
    if (m > 0.0f) {
        x = in->unk2; y = in->unk3;
        
        *angle = Math_Atan2S_XY(y, -x);
    } else {
        *angle = 0;
    }
}
