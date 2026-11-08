#include "types.h"
#include "generated/overlays/0125.h"
void func_800FF488(s32, f32);
f32 func_8017B984();
void func_80000470(s32 a) {
    f32 t = func_8017B984(a);
    if (t > 1.0f) {
        func_800FF488(a, 1.0f / t);
    }
}
