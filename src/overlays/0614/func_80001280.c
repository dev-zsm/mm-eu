#include "types.h"
extern u8 D_80BE41D0[];
extern void func_80BE3234(u8 *, s32, f32);
typedef struct { u8 pad0[0x284]; void *x284; u8 pad1[0x2A0 - 0x288]; s16 x2A0; } A;
void func_80001280(A *a0) {
    func_80BE3234((u8 *)a0, 0xF, 1.0f);
    a0->x2A0 = 3;
    a0->x284 = D_80BE41D0;
}
