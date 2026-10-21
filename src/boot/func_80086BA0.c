// FLAGS: -O2 -g0
#include "types.h"

extern f32 D_800976C4;
extern f32 D_8009938C;
extern f32 D_80099390;
extern f32 D_80099394;
extern f32 D_80099398;
f32 func_80086B60(f32 arg0);

f32 func_80086BA0(f32 arg0, f32 arg1) {
    if (arg1 == 0.0f) {
        if (arg0 == 0.0f) {
            return 0.0f;
        }
        if (0.0f < arg0) {
            return D_8009938C;
        }
        if (arg0 < 0.0f) {
            return D_80099390;
        }
        return D_800976C4;
    }
    if (0.0f <= arg1) {
        return func_80086B60(arg0 / arg1);
    }
    if (arg0 < 0.0f) {
        return func_80086B60(arg0 / arg1) - D_80099394;
    }
    return D_80099398 - func_80086B60(-(arg0 / arg1));
}
