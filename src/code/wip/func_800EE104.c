#include "types.h"

typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad0[0x2B0]; Gfx *polyOpa; } Gfxs;
typedef struct { Gfxs *gfx; } Play;

extern void Gfx_SetupDL23_Opa(Gfxs *g);
extern u32 Matrix_Finalize(Gfxs *g);
extern u32 D_801BBCA4[][9];

void GetItem_DrawBombchu(Play *play, s16 id) {
    Gfxs *g = play->gfx;
    Gfx *d;
    Gfx *e;

    Gfx_SetupDL23_Opa(g);
    d = g->polyOpa;
    g->polyOpa = d + 1;
    d->w0 = 0xDA380003;
    d->w1 = Matrix_Finalize(play->gfx);
    e = g->polyOpa;
    g->polyOpa = e + 1;
    e->w0 = 0xDE000000;
    e->w1 = D_801BBCA4[id][0];
}
