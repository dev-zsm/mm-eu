#include "types.h"
extern void func_800FF30C();
typedef struct { u8 pad0[0x16C]; void (*fn)(void *); } A;
void BgF40Block_Update(A *a) {
    a->fn(a);
    func_800FF30C((u8 *)a + 0x3C, (u8 *)a + 0x24);
}
