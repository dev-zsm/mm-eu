#include "types.h"
typedef struct { u8 pad0[0x28]; f32 a; u8 pad1[0x3C]; f32 b; u8 pad2[0x1C]; f32 c; u8 pad3[0x4AC]; f32 d; } A;
s32 func_80000C54(A *a) {
    f32 y = a->b;
    f32 x = a->a + (y + y);
    if (x - a->c <= a->d) {
        return 1;
    }
    return 0;
}
