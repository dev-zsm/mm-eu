#include "types.h"
typedef struct { u8 p0[0x98]; s32 a; f32 b; u8 p1[0x190-0xA0]; void *fn; u8 p2[0x20C-0x194]; s32 c; } A;
extern u8 D_8097D734[];
extern void func_800B87A0(s32, s32, s32, s32, f32);
void func_80000F24(A *a, s32 d) {
    func_800B87A0(a, d, a->c, a->a, a->b);
    a->fn = D_8097D734;
}
