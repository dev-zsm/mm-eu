#include "types.h"

typedef struct {
    u8 pad[0xB7];
    u8 a;
    u8 b;
} A;

s32 func_80000180(A *x) {
    if (x->b >= x->a) {
        x->a = 0;
    } else {
        x->a = x->a - x->b;
    }
    return x->a;
}
