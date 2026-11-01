#include "types.h"
extern u8 D_80A042DC[];
extern s32 func_801529DC();
typedef struct { u8 pad0[0x144]; void *x144; u8 pad1[0x17C - 0x148]; s16 x17C; } A;
void func_8000015C(A *a0, u8 *a1) {
if (func_801529DC(a1 + 0x4908) == 2) { a0->x17C = 2; a0->x144 = D_80A042DC; }
}
