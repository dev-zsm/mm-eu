#include "types.h"
typedef struct { u8 pad0[0x3D8]; s16 s; } S;
void func_80002FE4(S *a) {
    if (a->s <= 0) { a->s = 0; } else { a->s = a->s - 1; }
}
