#include "types.h"

typedef struct {
    u8 pad[0x70];
    f32 a;
    u8 p2[0x144 - 0x74];
    s32 b;
    u8 p3[0x208 - 0x148];
    s32 c;
    u8 p4[0x380 - 0x20C];
    s32 d;
} A;
void func_800072A0(A *x, s32 y) {
    x->c = 0;
    x->b = 0x12;
    x->d = 0;
    x->a = 0.0f;
}
