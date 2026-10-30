#include "types.h"

extern f32 D_80963824[];

f32 func_80000720(f32 a0, s32 a1) {
    f32 sq = a0 * a0;
    f32 t = D_80963824[a1];
    if (t < sq) {
        return t / sq;
    }
    return 1.0f;
}
