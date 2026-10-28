#include "types.h"
typedef struct A { u8 pad[0x144]; void (*f)(struct A *); } A;
void func_80000444(A *x) { x->f(x); }
