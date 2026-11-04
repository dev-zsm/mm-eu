// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kaleido_prompt.h"

void KaleidoScope_UpdatePrompt(PlayState* play) {
    static s16 sPromptAlphaTargetIndex = 0;
    static s16 sPromptAlphaTimer = 10;
    PauseContext* pauseCtx = &play->pauseCtx;
    Input* input = CONTROLLER1(&play->state);
    s8 stickAdjX = input->rel.stick_x;
    s16 alphaStep;

    if (((pauseCtx->state == PAUSE_STATE_SAVEPROMPT) && (pauseCtx->savePromptState == PAUSE_SAVEPROMPT_STATE_1)) ||
        (pauseCtx->state == PAUSE_STATE_GAMEOVER_SAVE_PROMPT) ||
        (pauseCtx->state == PAUSE_STATE_GAMEOVER_CONTINUE_PROMPT)) {

        
        if ((pauseCtx->promptChoice == PAUSE_PROMPT_YES) && (stickAdjX >= 30)) {
            
            Audio_PlaySfx(NA_SE_SY_CURSOR);
            pauseCtx->promptChoice = PAUSE_PROMPT_NO;
        } else if ((pauseCtx->promptChoice != PAUSE_PROMPT_YES) && (stickAdjX <= -30)) {
            
            Audio_PlaySfx(NA_SE_SY_CURSOR);
            pauseCtx->promptChoice = PAUSE_PROMPT_YES;
        }

        
        alphaStep = ABS_ALT(pauseCtx->promptAlpha - sPromptAlphaTargets[sPromptAlphaTargetIndex]) / sPromptAlphaTimer;

        if (pauseCtx->promptAlpha >= sPromptAlphaTargets[sPromptAlphaTargetIndex]) {
            pauseCtx->promptAlpha -= alphaStep;
        } else {
            pauseCtx->promptAlpha += alphaStep;
        }

        sPromptAlphaTimer--;
        if (sPromptAlphaTimer == 0) {
            pauseCtx->promptAlpha = sPromptAlphaTargets[sPromptAlphaTargetIndex];
            sPromptAlphaTimer = sPromptAlphaTargetIndex + 20;
            sPromptAlphaTargetIndex ^= 1;
        }
    }
}
