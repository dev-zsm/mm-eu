#include "types.h"
typedef struct { u8 p0[0x1A4]; void *fn; u8 p1[0x1C4-0x1A8]; f32 f; } A;
extern u8 D_80926500[];
extern void func_809235A0();
void func_80003130(A *a) {
    a->fn = D_80926500;
    func_809235A0(a, 7);
    a->f = 1.0f;
}
