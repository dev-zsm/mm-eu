// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (KaleidoScope_MoveCursorFromSpecialPos), score 0.00 (0 differ, size +0)
#include "generated/mm/z_kaleido_scope_NES.h"

void func_80009078(PlayState* play) {
    PauseContext* pauseCtx = &play->pauseCtx;

    pauseCtx->nameDisplayTimer = 0;
    pauseCtx->cursorSpecialPos = 0;

    Audio_PlaySfx(NA_SE_SY_CURSOR);

    pauseCtx->cursorShrinkRate = 4.0f;

    gSaveContext.buttonStatus[EQUIP_SLOT_B] = BTN_ENABLED;
    gSaveContext.buttonStatus[EQUIP_SLOT_C_LEFT] = gPageSwitchNextButtonStatus[pauseCtx->pageIndex + 1][1];
    gSaveContext.buttonStatus[EQUIP_SLOT_C_DOWN] = gPageSwitchNextButtonStatus[pauseCtx->pageIndex + 1][1];
    gSaveContext.buttonStatus[EQUIP_SLOT_C_RIGHT] = gPageSwitchNextButtonStatus[pauseCtx->pageIndex + 1][1];
    gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_ENABLED;

    gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;

    Interface_SetHudVisibility(HUD_VISIBILITY_ALL);
}
