#include "types.h"
typedef struct A { u8 pad[0x38C]; void (*fn)(struct A *, s32); } A;
extern void func_80B45C18();
void func_800005AC(A *a0, s32 a1) {
    a0->fn(a0, a1);
    func_80B45C18(a0, a1);
}
