#include "types.h"

extern f32 D_801D6924;
extern u8 D_801EE250[];
extern u8 D_801EE290[];

f32 sqrtf(f32);
#pragma intrinsic (sqrtf)

void Rumble_Request(f32 distSq, u8 sourceIntensity, u8 decayTimer, u8 decayStep) {
    s32 dist;
    s32 intensity;
    u8 *p;

    if (D_801D6924 < distSq) {
        dist = 1000;
    } else {
        dist = sqrtf(distSq);
    }
    if (dist < 1000 && sourceIntensity != 0 && decayStep != 0) {
        p = D_801EE250;
loop:
        if (p[4] == 0) {
            intensity = sourceIntensity - dist * 255 / 1000;
            if (intensity > 0) {
                p[4] = intensity;
                p[0x44] = decayTimer;
                p[0x84] = decayStep;
            }
        } else {
            p++;
            if (p != D_801EE290) {
                goto loop;
            }
        }
    }
}
