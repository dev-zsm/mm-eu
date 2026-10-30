#include "types.h"
extern u8 D_80ADB7A8[];
extern void func_800B8C4C();
typedef struct { u8 pad0[0x74]; f32 x74; u8 pad1[0x190 - 0x78]; void *x190; u8 pad2[0x19C - 0x194]; s16 x19C; } A;
void func_800002D8(A *a0) {
    a0->x19C = 0;
    a0->x74 = 0.0f;
    func_800B8C4C(a0, 0x4803);
    a0->x190 = D_80ADB7A8;
}
