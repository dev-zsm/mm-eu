#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 a;
    u8 pad1[0x55 - 5];
    u8 b;
    u8 pad2[0x95 - 0x56];
    u8 c;
} U;

typedef struct {
    u8 pad0[0x3A0];
    U *u;
} T;

void func_8000038C(T *a) {
    a->u->a = 0;
    a->u->b &= ~1;
    a->u->c &= ~1;
}
