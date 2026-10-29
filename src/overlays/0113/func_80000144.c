#include "types.h"

typedef struct {
    u8 pad[0x148];
    s16 a;
    s16 b;
} A;

extern s32 D_808D7E64[];

s32 func_80000144(A *x) {
    if (x->a == 0) {
        return D_808D7E64[x->b];
    }
    return x->a;
}
