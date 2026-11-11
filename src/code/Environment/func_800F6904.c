// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_UpdateTime(PlayState* play, EnvironmentContext* envCtx, PauseContext* pauseCtx, MessageContext* msgCtx,
                            GameOverContext* gameOverCtx) {
    u16 time;

    if (!sEnvIsTimeStopped && (pauseCtx->state == PAUSE_STATE_OFF) && (gameOverCtx->state == GAMEOVER_INACTIVE)) {
        if (((*(u8 *)((u8 *)msgCtx + 0x11F26)) == MSGMODE_NONE) || ((*(u16 *)((u8 *)msgCtx + 0x11F08)) == 0xF7) || ((*(u16 *)((u8 *)msgCtx + 0x11F08)) == 0x20D2) ||
            ((*(u16 *)((u8 *)msgCtx + 0x11F08)) == 0x140C) ||
            (((*(u16 *)((u8 *)msgCtx + 0x11F08)) >= 0x100) && ((*(u16 *)((u8 *)msgCtx + 0x11F08)) <= 0x200)) ||
            (gSaveContext.gameMode == GAMEMODE_END_CREDITS)) {
            if (!FrameAdvance_IsEnabled(play) &&
                ((play->transitionMode == TRANS_MODE_OFF) || (gSaveContext.gameMode != GAMEMODE_NORMAL))) {
                if (play->transitionTrigger == TRANS_TRIGGER_OFF) {
                    if ((CutsceneManager_GetCurrentCsId() == CS_ID_NONE) && !Play_InCsMode(play)) {
                        gSaveContext.save.time = CURRENT_TIME + (u16)R_TIME_SPEED;
                        if (R_TIME_SPEED != 0) {
                            gSaveContext.save.time = CURRENT_TIME + (u16)((void)0, gSaveContext.save.timeSpeedOffset);
                        }
                    }
                }
            }
        }
    }

    if ((((void)0, gSaveContext.skyboxTime) >= CLOCK_TIME(6, 0)) || (CURRENT_TIME < CLOCK_TIME(6, 0)) ||
        (CURRENT_TIME >= (CLOCK_TIME(6, 0) + 0x10))) {
        gSaveContext.skyboxTime = CURRENT_TIME;
    }

    time = CURRENT_TIME;

    if ((time >= CLOCK_TIME(18, 0)) || (time < CLOCK_TIME(6, 0))) {
        gSaveContext.save.isNight = true;
    } else {
        gSaveContext.save.isNight = false;
    }
}
