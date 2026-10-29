#include "types.h"

typedef struct {
    u8 pad[0x1AC];
    s16 a;
    s16 b;
    s16 c;
} A;

extern void func_800B6564(void *, f32);

void func_80000440(A *x) {
    x->c = 0;
    x->b = x->c;
    x->a = x->c;
    func_800B6564(x, 0);
}
