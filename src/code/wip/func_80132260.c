// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpa;
    u8 pad2B4[0xC];
    Gfx *polyXlu;
} GfxCtx;
typedef struct {
    u8 pad0[0x758];
    u8 flag18758;
    u8 pad759;
    s16 val1875A;
    s16 val1875C;
    u8 pad75E[0x10E];
    s32 unk1886C;
} Tail;
typedef struct {
    GfxCtx *gfx;
    u8 pad4[0x17FFC];
    Tail t;
} Play;

extern void AnimatedMat_Draw(s32 a, GfxCtx *b);
extern void Scene_SetRenderModeXlu(Play *a, s32 b, s32 c);

void Scene_DrawConfig5(Play *play) {
    s32 sp24;
    s32 alpha = 0xFF;
    GfxCtx *gfx;
    Gfx *dl;

    if (play->t.val1875A != 0) {
        sp24 = 1;
        alpha = play->t.val1875C;
    } else {
        sp24 = 0;
    }
    if (alpha == 0) {
        play->t.flag18758 = 0;
        return;
    }
    gfx = play->gfx;
    play->t.flag18758 = 1;
    AnimatedMat_Draw(play->t.unk1886C, gfx);
    Scene_SetRenderModeXlu(play, sp24, 3);
    dl = gfx->polyOpa++;
    dl->w0 = 0xFB000000; dl->w1 = (alpha & 0xFF) | ~0xFF;
    dl = gfx->polyXlu++;
    dl->w0 = 0xFB000000; dl->w1 = (alpha & 0xFF) | ~0xFF;
}
