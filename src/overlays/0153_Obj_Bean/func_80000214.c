#include "types.h"
typedef struct { u8 pad0[0x1AC]; s16 a; s16 b; s16 c; u8 pad1B2[0x16]; f32 f; } S1;
void func_80000214(S1 *p) {
    p->c = 0;
    p->b = p->c;
    p->a = p->c;
    p->f = 0.0f;
}
