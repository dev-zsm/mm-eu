// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_scope_call.h"

void KaleidoScopeCall_Update(PlayState* play) {
    PauseContext* pauseCtx = &play->pauseCtx;
    KaleidoMgrOverlay* kaleidoScopeOvl = &gKaleidoMgrOverlayTable[KALEIDO_OVL_KALEIDO_SCOPE];

    if (!IS_PAUSED(&play->pauseCtx)) {
        return;
    }

    if ((pauseCtx->state == PAUSE_STATE_OPENING_0) || (pauseCtx->state == PAUSE_STATE_OWL_WARP_0)) {
        if (ShrinkWindow_Letterbox_GetSize() == 0) {
            R_PAUSE_BG_PRERENDER_STATE = PAUSE_BG_PRERENDER_SETUP;
            pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE;
            pauseCtx->savePromptState = PAUSE_SAVEPROMPT_STATE_APPEARING;
            pauseCtx->state = (pauseCtx->state & 0xFFFF) + 1;
        }
    } else if (pauseCtx->state == PAUSE_STATE_GAMEOVER_0) {
        R_PAUSE_BG_PRERENDER_STATE = PAUSE_BG_PRERENDER_SETUP;
        pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE;
        pauseCtx->savePromptState = PAUSE_SAVEPROMPT_STATE_APPEARING;
        pauseCtx->state = (pauseCtx->state & 0xFFFF) + 1;
    } else if ((pauseCtx->state == PAUSE_STATE_OPENING_1) || (pauseCtx->state == PAUSE_STATE_GAMEOVER_1) ||
               (pauseCtx->state == PAUSE_STATE_OWL_WARP_1)) {
        if (R_PAUSE_BG_PRERENDER_STATE == PAUSE_BG_PRERENDER_READY) {
            pauseCtx->state++;
        }
    } else if (pauseCtx->state != PAUSE_STATE_OFF) {
        if (gKaleidoMgrCurOvl != kaleidoScopeOvl) {
            if (gKaleidoMgrCurOvl != NULL) {
                KaleidoManager_ClearOvl(gKaleidoMgrCurOvl);
            }

            KaleidoManager_LoadOvl(kaleidoScopeOvl);
        }

        if (gKaleidoMgrCurOvl == kaleidoScopeOvl) {
            sKaleidoScopeUpdateFunc(play);

            if (!IS_PAUSED(&play->pauseCtx)) {
                KaleidoManager_ClearOvl(kaleidoScopeOvl);
                KaleidoScopeCall_LoadPlayer();
            }
        }
    }
}
