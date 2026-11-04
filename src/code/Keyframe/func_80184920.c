// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/c_keyframe.h"

s16 Keyframe_KeyCalc(s16 kfStart, s16 kfNum, KeyFrame* keyFrames, f32 t) {
    KeyFrame* keyFramesOffset = &keyFrames[kfStart];
    f32 delta;
    s16 kf1;
    s16 kf2;

    if (t <= keyFramesOffset->frame) {
        return keyFramesOffset->value;
    }
    if (keyFramesOffset[kfNum - 1].frame <= t) {
        return keyFramesOffset[kfNum - 1].value;
    }

    kf1 = 0;
    kf2 = 1;
    while (true) {
        
        if (t < keyFramesOffset[kf2].frame) {
            delta = keyFramesOffset[kf2].frame - keyFramesOffset[kf1].frame;

            if (!IS_ZERO(delta)) {
                
                return nearbyint(Keyframe_Interpolate((t - keyFramesOffset[kf1].frame) / delta, delta * (1.0f / 30),
                                                      keyFramesOffset[kf1].value, keyFramesOffset[kf2].value,
                                                      keyFramesOffset[kf1].velocity, keyFramesOffset[kf2].velocity));
            } else {
                
                return keyFramesOffset[kf1].value;
            }
        }
        kf1++;
        kf2++;
    }
}
