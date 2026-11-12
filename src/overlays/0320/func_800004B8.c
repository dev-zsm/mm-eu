#include "types.h"
typedef struct { u32 w0; u32 w1; } G;
typedef struct { u8 pad[0x2B0]; G *g; } C;
typedef struct { C *c; } P;
typedef struct { u8 p[0x2B0]; s16 a; } T;
extern u8 D_600DE08[];
void func_800004B8(P *play, s32 limb, void *d, void *r, T *thisx) {
    T *this = thisx;
    if (limb == 0x10) {
        if (this->a >= 3 && this->a < 7) {
            C *gfx = play->c;
            if (1) { { G *g = gfx->g++; s32 pad; g->w0 = 0xDE000000; g->w1 = (u32) D_600DE08; }
            }
        }
    }
}
