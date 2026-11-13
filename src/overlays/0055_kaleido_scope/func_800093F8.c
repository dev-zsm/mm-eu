// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_scope_NES.h"

void func_800093F8(PlayState* play, Input* input) {
    PauseContext* pauseCtx = &play->pauseCtx;
    InterfaceContext* interfaceCtx = &play->interfaceCtx;


    if (1) {}

    if ((pauseCtx->debugEditor != DEBUG_EDITOR_NONE) || pauseCtx->itemDescriptionOn) {
        return;
    }

    if (CHECK_BTN_ALL(input->cur.button, BTN_DRIGHT) || CHECK_BTN_ALL(input->press.button, BTN_R)) {

        if (interfaceCtx->aButtonDoActionDelayed == DO_ACTION_DECIDE) {
            Interface_SetAButtonDoAction(play, DO_ACTION_INFO);
        }
        KaleidoScope_SwitchPage(pauseCtx, SWITCH_PAGE_RIGHT);
        return;
    }

    if (CHECK_BTN_ALL(input->cur.button, BTN_DLEFT) || CHECK_BTN_ALL(input->press.button, BTN_Z)) {

        if (interfaceCtx->aButtonDoActionDelayed == DO_ACTION_DECIDE) {
            Interface_SetAButtonDoAction(play, DO_ACTION_INFO);
        }
        KaleidoScope_SwitchPage(pauseCtx, SWITCH_PAGE_LEFT);
        return;
    }

    if (pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_LEFT) {
        if (pauseCtx->stickAdjX < -30) {
            pauseCtx->pageSwitchInputTimer++;

            if ((pauseCtx->pageSwitchInputTimer >= 10) || (pauseCtx->pageSwitchInputTimer == 0)) {
                KaleidoScope_SwitchPage(pauseCtx, SWITCH_PAGE_LEFT);
            }
        } else {

            pauseCtx->pageSwitchInputTimer = -1;
        }
    } else if (pauseCtx->cursorSpecialPos == PAUSE_CURSOR_PAGE_RIGHT) {
        if (pauseCtx->stickAdjX > 30) {
            pauseCtx->pageSwitchInputTimer++;

            if ((pauseCtx->pageSwitchInputTimer >= 10) || (pauseCtx->pageSwitchInputTimer == 0)) {
                KaleidoScope_SwitchPage(pauseCtx, SWITCH_PAGE_RIGHT);
            }
        } else {

            pauseCtx->pageSwitchInputTimer = -1;
        }
    }
}
