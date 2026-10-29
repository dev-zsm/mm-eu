#include "types.h"

typedef struct {
    u8 pad0[0x68];
    f32 a;
    u8 pad1[0x74 - 0x6C];
    f32 b;
    f32 c;
} T;

void func_800006E4(T *p) {
    f32 c = p->c;
    p->a = p->a + p->b;
    if (p->a < c) {
        p->a = c;
    }
}
