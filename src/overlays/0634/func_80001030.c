#include "types.h"
typedef struct { f32 x, y, z, w; } V;
s32 func_80001030(V v) {
    s32 r;
    if (v.z * v.y < v.x * v.w) {
        r = 1;
    } else {
        r = -1;
    }
    return r;
}
