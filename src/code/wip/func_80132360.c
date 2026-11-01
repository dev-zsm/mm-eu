#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    /* 0x000 */ u8 pad0[0x2B0];
    /* 0x2B0 */ Gfx *polyOpaHead;
    /* 0x2B4 */ Gfx *polyOpaTail;
    /* 0x2B8 */ u8 pad2B8[8];
    /* 0x2C0 */ Gfx *overlayHead;
} GraphicsContext;

typedef struct {
    /* 0x00000 */ GraphicsContext *gfxCtx;
    /* 0x00004 */ u8 pad4[0x82C];
    /* 0x00830 */ u8 colCtx[0x1803C];
    /* 0x1886C */ u32 unk1886C;
} PlayState;

extern Gfx D_801C4948[];

extern s32 Flags_GetSwitch(PlayState *play, s32 flag);
extern void BgCheck_SetContextFlags(void *colCtx, s32 flags);
extern void BgCheck_UnsetContextFlags(void *colCtx, s32 flags);
extern void AnimatedMat_Draw(PlayState *play, u32 matAnim);
extern void func_80091460(void *src, void *dst, s32 size);

void Scene_DrawConfigGreatBayTemple(PlayState *play) {
    s32 padA[4];
    GraphicsContext *gfxCtx;
    s32 padB[4];
    Gfx *dl;
    Gfx *cur;
    s32 i;
    u32 color;

    if (Flags_GetSwitch(play, 0x33) && Flags_GetSwitch(play, 0x34) && Flags_GetSwitch(play, 0x35) &&
        Flags_GetSwitch(play, 0x36)) {
        BgCheck_SetContextFlags(play->colCtx, 1);
    } else {
        BgCheck_UnsetContextFlags(play->colCtx, 1);
    }

    {
        GraphicsContext *ctx = play->gfxCtx;

        dl = ctx->polyOpaTail - 18;
        ctx->polyOpaTail = dl;
    }
    AnimatedMat_Draw(play, play->unk1886C);

    gfxCtx = play->gfxCtx;
    cur = dl;
    for (i = 0; i < 9; i++) {
        color = 0;
        func_80091460(D_801C4948, cur, 0x10);
        switch (i) {
            case 0:
                if (Flags_GetSwitch(play, 0x33) && Flags_GetSwitch(play, 0x34) && Flags_GetSwitch(play, 0x35) &&
                    Flags_GetSwitch(play, 0x36)) {
                    color = 0xFF;
                }
                break;
            case 1:
                if (Flags_GetSwitch(play, 0x37)) {
                    color = 0x44;
                }
                break;
            case 2:
                if (Flags_GetSwitch(play, 0x37) && Flags_GetSwitch(play, 0x38)) {
                    color = 0x44;
                }
                break;
            case 3:
                if (Flags_GetSwitch(play, 0x37) && Flags_GetSwitch(play, 0x38) && Flags_GetSwitch(play, 0x39)) {
                    color = 0x44;
                }
                break;
            case 4:
                if (!Flags_GetSwitch(play, 0x33)) {
                    color = 0x44;
                }
                break;
            case 5:
                if (Flags_GetSwitch(play, 0x34)) {
                    color = 0x44;
                }
                break;
            case 6:
                if (Flags_GetSwitch(play, 0x34) && Flags_GetSwitch(play, 0x35)) {
                    color = 0x44;
                }
                break;
            case 7:
                if (Flags_GetSwitch(play, 0x34) && Flags_GetSwitch(play, 0x35) && Flags_GetSwitch(play, 0x36)) {
                    color = 0x44;
                }
                break;
            case 8:
                if (Flags_GetSwitch(play, 0x3A)) {
                    color = 0x44;
                }
                break;
        }
        cur->w0 = 0xFA000000 | (color & 0xFF);
        cur->w1 = 0xFFFFFFFF;
        cur += 2;
    }

    { Gfx *_g = gfxCtx->polyOpaHead++; _g->w0 = 0xDB060018; _g->w1 = (u32)dl; }
    { Gfx *_g = gfxCtx->overlayHead++; _g->w0 = 0xDB060018; _g->w1 = (u32)dl; }
}
