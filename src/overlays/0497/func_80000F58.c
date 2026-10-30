#include "types.h"
typedef struct { u8 pad[0x268]; void (*fn)(); } A;
extern void func_80B4B034();
void func_80000F58(A *a, s32 b) {
    a->fn(a, b);
    func_80B4B034(a, b);
}
