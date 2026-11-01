#include "types.h"

typedef struct {
    u8 p0[0x1C];
    s16 s;
    u8 p1[0x70 - 0x1E];
    f32 g;
    u8 p2[0x144 - 0x74];
    void *f;
} A;
extern u8 D_808CA1BC[];
void func_80000A18(A *x) {
    A *new_var;
    x->s = 0;
    new_var = x;
    new_var->f = D_808CA1BC;
    x->g = 5.0f;
}
