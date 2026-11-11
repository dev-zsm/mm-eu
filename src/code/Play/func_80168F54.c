// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_Update(PlayState* this) {
    if (!sBombersNotebookOpen) {
        if (this->pauseCtx.bombersNotebookOpen) {
            sBombersNotebookOpen = true;
            sBombersNotebook.loadState = BOMBERS_NOTEBOOK_LOAD_STATE_NONE;
        }
    } else if (CHECK_BTN_ALL(CONTROLLER1(&this->state)->press.button, BTN_L) ||
               CHECK_BTN_ALL(CONTROLLER1(&this->state)->press.button, BTN_B) ||
               CHECK_BTN_ALL(CONTROLLER1(&this->state)->press.button, BTN_START) ||
               (gIrqMgrResetStatus != IRQ_RESET_STATUS_IDLE)) {
        sBombersNotebookOpen = false;
        this->pauseCtx.bombersNotebookOpen = false;
        sBombersNotebook.loadState = BOMBERS_NOTEBOOK_LOAD_STATE_NONE;
        ((MessageContext *)((u8 *)&this->msgCtx + 4))->msgLength = 0;
        ((MessageContext *)((u8 *)&this->msgCtx + 4))->msgMode = MSGMODE_NONE;
        ((MessageContext *)((u8 *)&this->msgCtx + 4))->currentTextId = 0;
        ((MessageContext *)((u8 *)&this->msgCtx + 4))->stateTimer = 0;
        Audio_PlaySfx(NA_SE_SY_CANCEL);
    }
    if (sBombersNotebookOpen) {
        BombersNotebook_Update(this, &sBombersNotebook, this->state.input);
        Message_Update(this);
    } else {
        Play_UpdateMain(this);
    }
}
