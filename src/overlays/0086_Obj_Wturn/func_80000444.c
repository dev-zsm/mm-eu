#include "types.h"
typedef struct A { u8 pad[0x144]; void (*f)(struct A *); } A;
void ObjWturn_Update(A *x) { x->f(x); }
