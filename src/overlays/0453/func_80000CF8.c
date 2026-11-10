#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} G;
typedef struct {
    u8 pad[0x2B0];
    G *g;
} C;
typedef struct {
    C *c;
} P;
extern u8 D_6007610[];
void func_80000CF8(P *play, s32 b, s32 c2, s32 d) {
    if (b == 1) {
        C *gfx = play->c;
        // one line: the ROM's scheduling depends on these stores sharing a single source line
        if (1) { { G *g = gfx->g++; s32 pad; g->w0 = 0xDE000000; g->w1 = (u32) D_6007610; }
        }
    }
}
