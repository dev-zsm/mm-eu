#include "types.h"
extern void func_800FF30C();
typedef struct { u8 pad0[0x16C]; void (*fn)(void *); } A;
void func_80000C0C(A *a) {
    a->fn(a);
    func_800FF30C((u8 *)a + 0x3C, (u8 *)a + 0x24);
}
