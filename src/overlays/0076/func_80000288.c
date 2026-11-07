#include "types.h"
typedef struct { u8 pad0[0x92]; s16 a92; u8 pad1[0x2A]; s16 aBE; u8 pad2[0x1CE]; s16 a28E; } A;
s32 func_80000288(A *a) {
    s16 t = a->a92 - a->a28E - a->aBE;
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
