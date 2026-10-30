#include "types.h"
typedef struct { u8 p0[0xC]; f32 c; u8 p1[0x28-0x10]; f32 a; u8 p2[0x9C-0x2C]; f32 b; } A;
f32 func_80000558(A *x) {
    f32 t = x->a + x->b + 60.0f;
    f32 c = x->c;
    if (c < t) {
        return c;
    }
    return t;
}
