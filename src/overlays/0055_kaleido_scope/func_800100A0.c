// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_scope_NES.h"

void func_800100A0(PlayState* play) {
    PauseContext* pauseCtx = &play->pauseCtx;

    pauseCtx->eye.x += sPageSwitchEyeDx[pauseCtx->nextPageMode] * 2.0f;
    pauseCtx->eye.z += sPageSwitchEyeDz[pauseCtx->nextPageMode] * 2.0f;
    pauseCtx->switchPageTimer += 8;

    if (pauseCtx->switchPageTimer == 64) {

        Interface_UpdateButtonsAlt(play, 1);

        if (pauseCtx->cursorSpecialPos == 0) {
            gSaveContext.buttonStatus[EQUIP_SLOT_B] = gPageSwitchNextButtonStatus[pauseCtx->pageIndex][0];
            gSaveContext.buttonStatus[EQUIP_SLOT_C_LEFT] = gPageSwitchNextButtonStatus[pauseCtx->pageIndex][1];
            gSaveContext.buttonStatus[EQUIP_SLOT_C_DOWN] = gPageSwitchNextButtonStatus[pauseCtx->pageIndex][1];
            gSaveContext.buttonStatus[EQUIP_SLOT_C_RIGHT] = gPageSwitchNextButtonStatus[pauseCtx->pageIndex][1];
            gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_ENABLED;
        } else {
            gSaveContext.buttonStatus[EQUIP_SLOT_B] = BTN_ENABLED;
            gSaveContext.buttonStatus[EQUIP_SLOT_C_LEFT] = BTN_DISABLED;
            gSaveContext.buttonStatus[EQUIP_SLOT_C_DOWN] = BTN_DISABLED;
            gSaveContext.buttonStatus[EQUIP_SLOT_C_RIGHT] = BTN_DISABLED;
            gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_DISABLED;
        }

        pauseCtx->pageIndex = sPageSwitchNextPageIndex[pauseCtx->nextPageMode];
        pauseCtx->mainState = PAUSE_MAIN_STATE_IDLE;
        pauseCtx->state++;
        pauseCtx->alpha = 255;
        Interface_SetBButtonInterfaceDoAction(play, DO_ACTION_RETURN);
    } else if (pauseCtx->switchPageTimer == 64) {
        pauseCtx->pageIndex = sPageSwitchNextPageIndex[pauseCtx->nextPageMode];
        pauseCtx->nextPageMode = (pauseCtx->pageIndex * 2) + 1;
    }
}
