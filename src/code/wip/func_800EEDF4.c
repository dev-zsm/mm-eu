#include "types.h"

typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad0[0x2B0]; Gfx *p; } GfxCtx;
typedef struct { GfxCtx *gfx; } Play;
typedef struct { void *p; u8 pad[0x20]; } Ent;

extern Ent D_801BBCA4[];
extern void Gfx_SetupDL25_Opa(GfxCtx *);
extern u32 Matrix_Finalize(GfxCtx *);

void GetItem_DrawOpa0(Play *play, s16 id) {
    GfxCtx *gfx = play->gfx;

    Gfx_SetupDL25_Opa(gfx);
    {
        GfxCtx *g = gfx;
        s32 pad;
        Gfx *dl;

        dl = g->p++;
        dl->w0 = 0xDA380003;
        dl->w1 = Matrix_Finalize(play->gfx);
        dl = g->p++;
        dl->w0 = 0xDE000000;
        dl->w1 = (u32)D_801BBCA4[id].p;
    }
}
