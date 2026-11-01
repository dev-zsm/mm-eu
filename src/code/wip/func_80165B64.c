#include "types.h"

typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad0[4]; u8 r, g, b, a; } Fade;
extern u8 D_801C9590[];
extern u8 D_E0002E0[];

void TransitionFade_Draw(Fade *fade, Gfx **gfxp) {
    Gfx *g;
    Gfx *p;
    u8 *c;

    if (fade->a != 0) {
        g = *gfxp;
        p = g;
        p->w0 = 0xDE000000;
        p->w1 = (u32)D_801C9590;
        g++;
        p = g;
        p->w0 = 0xFA000000;
        c = &fade->r;
        p->w1 = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
        g++;
        p = g;
        p->w1 = (u32)D_E0002E0;
        p->w0 = 0xDE000000;
        g++;
        *gfxp = g;
    }
}
