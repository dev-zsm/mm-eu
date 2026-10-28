#include "types.h"
typedef struct { u8 pad0[0x146]; u8 u; } S;
void func_800003E8(S *a, s32 b) {
    if (a->u < 0x64) { a->u = a->u + 5; }
}
