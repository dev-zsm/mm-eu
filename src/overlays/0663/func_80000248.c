#include "types.h"
typedef struct A { u8 pad[0x194]; void (*fn)(struct A *, s32); } A;
extern void func_80C0A640();
void func_80000248(A *a0, s32 a1) {
    a0->fn(a0, a1);
    func_80C0A640(a0, a1);
}
