#include "types.h"
typedef struct A { u8 pad[0x1C8]; void (*f)(struct A *); } A;
void func_80000B2C(A *x) { x->f(x); }
