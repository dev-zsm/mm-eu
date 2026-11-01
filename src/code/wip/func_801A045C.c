#include "types.h"
extern f32 D_801D864C;
extern f32 D_801D8650;
extern f32 D_801D8654;
extern f32 D_801D8658;
extern f32 D_801D865C;
extern f32 D_801F4A9C;
extern f32 D_801F4AA4;
f32 Audio_SetSyncedSfxFreqAndVolume(f32 arg0) {
    f32 t = 1.0f;
    if (6.0f < arg0) {
        D_801F4A9C = 1.0f;
        D_801F4AA4 = D_801D864C;
    } else {
        t = arg0 / 6.0f;
        D_801F4A9C = (t * D_801D8650) + D_801D8654;
        D_801F4AA4 = (t * D_801D8658) + D_801D865C;
    }
    return t;
}
