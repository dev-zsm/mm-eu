#include "types.h"

typedef struct { u8 p0[0x2B8]; u8 *u2B8; } A;
extern void (*D_80B89ECC[])();

void func_8000154C(A *a) {
    D_80B89ECC[*a->u2B8]();
}
