// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_scope_NES.h"

void func_8000D194(PlayState* play, Input* input) {
    PauseContext* pauseCtx = &play->pauseCtx;


    if (1) {
        pauseCtx->eye.x += sPageSwitchEyeDx[pauseCtx->nextPageMode] * 2.0f;
        pauseCtx->eye.z += sPageSwitchEyeDz[pauseCtx->nextPageMode] * 2.0f;

        if (pauseCtx->switchPageTimer < 32) {
            sPauseCursorLeftX -= TRUNCF_BINANG(sPauseCursorLeftMoveOffsetX / 4);
            sPauseCursorRightX -= TRUNCF_BINANG(sPauseCursorRightMoveOffsetX / 4);
        } else {
            sPauseCursorLeftX += TRUNCF_BINANG(sPauseCursorLeftMoveOffsetX / 4);
            sPauseCursorRightX += TRUNCF_BINANG(sPauseCursorRightMoveOffsetX / 4);
        }

        pauseCtx->switchPageTimer += 8;

        if (pauseCtx->switchPageTimer == 64) {
            pauseCtx->switchPageTimer = 0;
            pauseCtx->pageIndex = sPageSwitchNextPageIndex[pauseCtx->nextPageMode];
            pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE;

            KaleidoScope_HandlePageToggles(play, input);
        }
    }
}
