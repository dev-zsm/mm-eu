// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_Destroy(GameState* thisx) {
    PlayState* this = (PlayState*)thisx;
    GraphicsContext* gfxCtx = this->state.gfxCtx;

    if (sBombersNotebookOpen) {
        Sched_FlushTaskQueue();
        SysCfb_SetLoResMode();
        gfxCtx->curFrameBuffer = SysCfb_GetFramebuffer(gfxCtx->framebufferIndex % 2);
        gfxCtx->zbuffer = SysCfb_GetZBuffer();
        gfxCtx->viMode = gActiveViMode;
        gfxCtx->viConfigFeatures = gViConfigFeatures;
        gfxCtx->xScale = gViConfigXScale;
        gfxCtx->yScale = gViConfigYScale;
        gfxCtx->updateViMode = true;
        sBombersNotebookOpen = false;
    }

    BombersNotebook_Destroy(&sBombersNotebook);
    this->state.gfxCtx->callback = NULL;
    this->state.gfxCtx->callbackArg = NULL;
    Play_DestroyMotionBlur();

    if (R_PAUSE_BG_PRERENDER_STATE != PAUSE_BG_PRERENDER_OFF) {
        PreRender_ApplyFiltersSlowlyDestroy(&this->pauseBgPreRender);
        R_PAUSE_BG_PRERENDER_STATE = PAUSE_BG_PRERENDER_OFF;
    }

    R_PICTO_PHOTO_STATE = PICTO_PHOTO_STATE_OFF;
    PreRender_Destroy(&this->pauseBgPreRender);
    this->unk_18E58 = NULL;
    this->pictoPhotoI8 = NULL;
    this->unk_18E60 = NULL;
    this->unk_18E64 = NULL;
    this->unk_18E68 = NULL;
    Effect_DestroyAll(this);
    EffectSs_ClearAll(this);
    CollisionCheck_DestroyContext(this, &this->colChkCtx);

    if (gTransitionTileState == TRANS_TILE_READY) {
        TransitionTile_Destroy(&sTransitionTile);
        gTransitionTileState = TRANS_TILE_OFF;
    }

    if ((this->transitionMode == TRANS_MODE_INSTANCE_RUNNING) || ref_D_801D0D54) {
        this->transitionCtx.destroy(&this->transitionCtx.instanceData);
        Play_ClearTransition(this);
        this->transitionMode = TRANS_MODE_OFF;
    }

    ShrinkWindow_Destroy();
    TransitionFade_Destroy(&this->unk_18E48);
    VisMono_Destroy(&sPlayVisMono);
    VisFbuf_Destroy(sPlayVisFbufInstance);
    sPlayVisFbufInstance = NULL;

    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_92_80)) {
        Actor_CleanupContext(&this->actorCtx, this);
    }
    CLEAR_WEEKEVENTREG(WEEKEVENTREG_92_80);

    Interface_Destroy(this);
    KaleidoScopeCall_Destroy(this);
    KaleidoManager_Destroy();
    ZeldaArena_Cleanup();
}
