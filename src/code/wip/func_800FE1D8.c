#include "types.h"
typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad0[0x2B0]; Gfx *unk2B0; } Gc;
typedef struct { Gc *gfxCtx; } Pl;
extern Gfx *D_801EC6B4;
Gfx *Gfx_Open(Gfx *);
void Gfx_Close(Gfx *, Gfx *);
void Environment_DrawSkyboxStarsImpl(Pl *, Gfx **);
void Environment_DrawSkyboxStars(Pl *play) {
    Gfx *sp2C;
    Gfx *sp28;
    Gc *sp24;
    Gfx *g;
    Gfx *d;
    if (D_801EC6B4 != NULL) {
        sp24 = play->gfxCtx;
        sp28 = sp24->unk2B0;
        sp2C = Gfx_Open(sp28);
        d = D_801EC6B4;
        d->w0 = 0xDE000000;
        d->w1 = (u32)sp2C;
        Environment_DrawSkyboxStarsImpl(play, &sp2C);
        g = sp2C++;
        g->w1 = 0;
        g->w0 = 0xDF000000;
        Gfx_Close(sp28, sp2C);
        sp24->unk2B0 = sp2C;
        D_801EC6B4 = NULL;
    }
}
