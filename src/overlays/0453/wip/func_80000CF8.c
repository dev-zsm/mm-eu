#include "types.h"
typedef struct { u32 w0; u32 w1; } G;
typedef struct { u8 pad[0x2B0]; G *g; } C;
extern u8 D_6007610;
void func_80000CF8(C **c, s32 b, s32 c2, s32 d) {
    if (b == 1) {
        C *gc = *c;
        G *g = gc->g++;
        g->w0 = 0xDE000000;
        g->w1 = (u32)&D_6007610;
    }
}
