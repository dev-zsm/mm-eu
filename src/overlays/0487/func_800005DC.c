#include "types.h"
typedef struct A { u8 pad[0x15C]; void (*fn)(); } A;
extern void func_80B250C4();
void func_800005DC(A *a, s32 b) {
    a->fn(a, b);
    func_80B250C4(a, b);
}
