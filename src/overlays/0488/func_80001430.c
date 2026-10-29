#include "types.h"
typedef struct { u8 p0[0x304]; void *u304; } A;
typedef struct { u8 p0[0xA88]; A *uA88; } B;
typedef struct { u8 p0[0x1CCC]; B *u1CCC; } C;
extern u8 D_80B27238[];
void func_80001430(A *a, C *c) {
    B *b = c->u1CCC;
    void *p = D_80B27238;
    if (a != b->uA88) {
        a->u304 = p;
    }
}
