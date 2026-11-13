// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;
typedef struct {
    u8 pad[0x2B0];
    Gfx *p;
} GfxCtx;
typedef struct {
    GfxCtx *gfxCtx;
} Play;
extern u8 D_80BDE610[];
extern u8 D_80BDEDB0[];
void func_80182B28();
void func_800002CC(Play *play, s32 limbIndex, s32 a2, s32 a3, u8 *actor) {
    GfxCtx *gfx;
    if (limbIndex == 0xF) {
        func_80182B28(D_80BDEDB0, actor + 0x3C);
        if (1) {
            gfx = play->gfxCtx;
        } {
            Gfx *g = gfx->p++;
            // one line: the ROM's scheduling depends on these stores sharing a single source line
            g->w0 = 0xDE000000; g->w1 = (u32) D_80BDE610;
        }
    }
}
