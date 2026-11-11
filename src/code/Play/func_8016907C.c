// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_PostWorldDraw(PlayState* this) {
    if (IS_PAUSED(&this->pauseCtx)) {
        KaleidoScopeCall_Draw(this);
    }

    if (gSaveContext.gameMode == GAMEMODE_NORMAL) {
        Interface_Draw(this);
    }

    if (!IS_PAUSED(&this->pauseCtx) || ((*(u16 *)((u8 *)this + 0x16810)) != 0xFF)) {
        Message_Draw(this);
    }

    if (this->gameOverCtx.state != GAMEOVER_INACTIVE) {
        GameOver_FadeLights(this);
    }

    
    if (gSaveContext.screenScaleFlag) {
        Gfx* gfx;
        Gfx* gfxHead;
        GraphicsContext* gfxCtx = this->state.gfxCtx;

        sPlayVisFbufInstance->scale = gSaveContext.screenScale / 1000.0f;

        OPEN_DISPS(gfxCtx);

        gfxHead = POLY_OPA_DISP;
        gfx = Gfx_Open(gfxHead);
        gSPDisplayList(OVERLAY_DISP++, gfx);

        VisFbuf_Draw(sPlayVisFbufInstance, &gfx, this->unk_18E60);

        gSPEndDisplayList(gfx++);
        Gfx_Close(gfxHead, gfx);
        POLY_OPA_DISP = gfx;

        CLOSE_DISPS(gfxCtx);
    }
}
