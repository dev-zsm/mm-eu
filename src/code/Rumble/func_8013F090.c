// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_rumble.h"

void Rumble_Request(f32 distSq, u8 sourceIntensity, u8 decayTimer, u8 decayStep) {
    s32 intensity;
    s32 distance;
    s32 i;

    if (SQ(1000.0f) < distSq) {
        distance = 1000;
    } else {
        distance = sqrtf(distSq);
    }

    if ((distance < 1000) && (sourceIntensity != 0) && (decayStep != 0)) {
        intensity = sourceIntensity - (distance * 255) / 1000;

        for (i = 0; i < RUMBLE_REQUEST_BUFFER_SIZE; i++) {
            if (gRumbleMgr.requestIntensities[i] == 0) {
                if (intensity > 0) {
                    gRumbleMgr.requestIntensities[i] = intensity;
                    gRumbleMgr.requestDecayTimers[i] = decayTimer;
                    gRumbleMgr.requestDecaySteps[i] = decayStep;
                }
                break;
            }
        }
    }
}
