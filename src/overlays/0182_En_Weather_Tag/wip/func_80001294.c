// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnWeatherTag_Update), score 2.00 (2 differ, size +0)
#include "generated/mm/z_en_weather_tag.h"

void func_80001294(Actor* thisx, PlayState* play) {
    EnWeatherTag* this = (EnWeatherTag*)thisx;

    this->actionFunc(this, play);

    if ((play->actorCtx.flags & ACTORCTX_FLAG_TELESCOPE_ON) && (play->msgCtx.msgMode != MSGMODE_NONE) &&
        (play->msgCtx.currentTextId == 0x5E6) && !FrameAdvance_IsEnabled(play) &&
        (play->transitionTrigger == TRANS_TRIGGER_OFF) && (CutsceneManager_GetCurrentCsId() == CS_ID_NONE) &&
        (play->csCtx.state == CS_STATE_IDLE)) {

        gSaveContext.save.time = CURRENT_TIME + (u16)R_TIME_SPEED;
        if (R_TIME_SPEED != 0) {
            gSaveContext.save.time = CURRENT_TIME + (u16)((void)0, gSaveContext.save.timeSpeedOffset);
        }
    }
}
