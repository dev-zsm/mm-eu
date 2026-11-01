// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    u8 pad0[0x100];
    f32 unk100;
} Camera;

extern f32 D_801D4EB0;
extern f32 D_801D4EB4;

// 11 instructions differ: float register allocation only.
f32 Camera_ClampLerpScale(Camera *camera, f32 maxLerpScale) {
    f32 scale;

    if (camera->unk100 < D_801D4EB0) {
        scale = D_801D4EB0;
    } else if (maxLerpScale <= camera->unk100) {
        scale = maxLerpScale;
    } else {
        scale = camera->unk100 * D_801D4EB4;
    }
    return scale;
}
