#include "types.h"
typedef struct { u8 p0[0x1E5]; u8 u1E5; } A;
void func_80000210(A *a, u8 b) {
    a->u1E5 &= 0xFFF8;
    a->u1E5 |= b;
}
