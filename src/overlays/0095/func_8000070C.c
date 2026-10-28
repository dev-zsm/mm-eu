#include "types.h"
typedef struct A { u8 pad[0x160]; void (*unk160)(struct A *); } A;
void func_8000070C(A *a) {
    a->unk160(a);
}
