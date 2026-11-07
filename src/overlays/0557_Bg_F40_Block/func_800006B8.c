#include "types.h"
typedef struct { u8 pad[0x160]; s32 a; s32 b; s32 c; } A;
void func_800006B8(A *p) {
    s32 t = p->a;
    p->a = p->b;
    p->b = t;
    p->c = 6;
}
