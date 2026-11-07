#include "types.h"
typedef struct { u8 pad0[0x92]; s16 a92; u8 pad1[0x2A]; s16 aBE; } A;
s32 func_80001B34(A *a, s32 b) {
    s16 t = a->a92 - a->aBE;
    s32 x;
    if (t < 0) {
        x = -t;
    } else {
        x = t;
    }
    if (x < 0x3000) {
        return 1;
    }
    return 0;
}
