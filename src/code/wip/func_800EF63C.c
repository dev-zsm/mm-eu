#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *dl;
} GfxCtx;

typedef struct {
    GfxCtx *gfx;
} Play;

typedef struct {
    u32 pad0;
    u32 w4;
    u32 w8;
    u32 wC;
    u32 w10;
    u32 pad14[4];
} Entry;

extern Entry D_801BBCA0[];
extern void Gfx_SetupDL25_Opa();
extern u32 Matrix_Finalize();

#define PUSH(g, a, b) { Gfx *_g = (g)->dl++; _g->w0 = (a); _g->w1 = (b); }

void GetItem_DrawUpgrades(Play *play, s16 idx) {
    s32 pad; GfxCtx *gfx = play->gfx;

    Entry *e;
    Gfx_SetupDL25_Opa(gfx);
    PUSH(gfx, 0xDA380003, Matrix_Finalize(play->gfx));
    e = &D_801BBCA0[idx];
    PUSH(gfx, 0xDE000000, e->w8);
    PUSH(gfx, 0xDE000000, e->w4);
    PUSH(gfx, 0xDE000000, e->wC);
    PUSH(gfx, 0xDE000000, e->w10);
}
