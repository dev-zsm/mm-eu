#include "types.h"
extern f32 D_80963824[];
f32 func_800006E4(f32 a0, s32 a1) {
    f32 t = D_80963824[a1];
    if (t < a0) {
        return t / a0;
    }
    return 1.0f;
}
