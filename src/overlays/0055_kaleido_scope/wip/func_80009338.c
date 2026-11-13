// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (KaleidoScope_SwitchPage), score 0.00 (0 differ, size +0)
#include "generated/mm/z_kaleido_scope_NES.h"

void func_80009338(PauseContext* pauseCtx, u8 direction) {
    pauseCtx->cursorSlot[pauseCtx->pageIndex] = 0;
    pauseCtx->mainState = PAUSE_MAIN_STATE_SWITCHING_PAGE;
    pauseCtx->switchPageTimer = 0;

    if (direction == SWITCH_PAGE_LEFT) {
        pauseCtx->nextPageMode = (pauseCtx->pageIndex * 2) + 1;
        Audio_PlaySfx(NA_SE_SY_WIN_SCROLL_LEFT);
        pauseCtx->cursorSpecialPos = PAUSE_CURSOR_PAGE_RIGHT;
    } else { 
        pauseCtx->nextPageMode = pauseCtx->pageIndex * 2;
        Audio_PlaySfx(NA_SE_SY_WIN_SCROLL_RIGHT);
        pauseCtx->cursorSpecialPos = PAUSE_CURSOR_PAGE_LEFT;
    }

    gSaveContext.buttonStatus[EQUIP_SLOT_B] = BTN_ENABLED;
    gSaveContext.buttonStatus[EQUIP_SLOT_C_LEFT] = BTN_DISABLED;
    gSaveContext.buttonStatus[EQUIP_SLOT_C_DOWN] = BTN_DISABLED;
    gSaveContext.buttonStatus[EQUIP_SLOT_C_RIGHT] = BTN_DISABLED;
    gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_DISABLED;

    gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
    Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
}
