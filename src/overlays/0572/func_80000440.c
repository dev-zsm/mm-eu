#include "types.h"

typedef struct {
    u8 pad0[0x162];
    s16 x;
} T;

s32 func_80000440(T *a, s32 b) {
    if (a->x < 0x5555) { a->x = a->x + 0x1388; } else { return 1; } return 0;
}
