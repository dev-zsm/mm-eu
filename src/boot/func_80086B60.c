// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0E0;
f32 func_800868F0(f32 arg0);
f32 func_80086A14(f32 arg0);

f32 func_80086B60(f32 arg0) {
    if (D_8009D0E0 == 0) {
        return func_800868F0(arg0);
    }
    return func_80086A14(arg0);
}
