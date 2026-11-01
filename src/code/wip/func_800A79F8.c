// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct {
    u8 pad0[0x2C0];
    Gfx *polyXlu;
} GfxCtx;
typedef struct {
    GfxCtx *gfx;
} Play;
typedef struct {
    u8 pad0[0x1E];
    s8 params;
} Actor;

extern u8 D_6001290[];
extern u8 D_6001470[];
extern s32 Object_GetSlot(void *a, s32 b);
extern void func_8012C78C(GfxCtx *g);
extern void Matrix_Scale(f32 x, f32 y, f32 z, s32 mode);
extern u32 Matrix_Finalize(GfxCtx *g);

void EnItem00_DrawHeartContainer(Actor *actor, Play *play) {
    GfxCtx *gfx;
    Gfx *dispRefs[4];
    Gfx *dl;

    if (Object_GetSlot((u8 *)play + 0x17D88, 0x96) == actor->params) {
        func_8012C78C(gfx = play->gfx);
        Matrix_Scale(20.0f, 20.0f, 20.0f, 1);
        dl = gfx->polyXlu++;
        dl->w0 = 0xDA380003;
        dl->w1 = Matrix_Finalize(play->gfx);
        dl = gfx->polyXlu++;
        dl->w0 = 0xDE000000; dl->w1 = (u32)D_6001290;
        dl = gfx->polyXlu++;
        dl->w0 = 0xDE000000; dl->w1 = (u32)D_6001470;
    }
}
