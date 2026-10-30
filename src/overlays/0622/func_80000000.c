#include "types.h"
typedef struct { u8 p0[0xC0]; s16 a; u8 p1[0x144-0xC2]; s16 b; u8 p2[2]; void *fn; } A;
extern u8 D_80BEC530[];
extern void func_800B6564();
void func_80000000(A *a, s32 b) {
    func_800B6564(a, 0x3F800000);
    a->fn = D_80BEC530;
    a->b = 0;
    a->a = 0;
}
