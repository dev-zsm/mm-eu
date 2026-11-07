// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_daytelop.h"

void DayTelop_Update(DayTelopState* this, GameState* thisx) {
    static u8 ref_D_80815FF0 = 0;
    s16 new_var;
    u8 temp_v0_2;

    this->transitionCountdown--;
    if (this->transitionCountdown == 0) {
        if (gSaveContext.save.day < 9) {
            gSaveContext.gameMode = GAMEMODE_NORMAL;
        } else {
            gSaveContext.nextCutsceneIndex = 0xFFF6;
            gSaveContext.save.day = 1;
        }

        STOP_GAMESTATE(&this->state);
        SET_NEXT_GAMESTATE(&this->state, Play_Init, sizeof(PlayState));

        gSaveContext.save.time = CLOCK_TIME(6, 0);
        gSceneSeqState = SCENESEQ_MORNING;
    } else if (this->transitionCountdown == 90) {
        this->fadeInState = DAYTELOP_HOURSTEXT_FADEIN;
        this->alpha = 0;
        ref_D_80815FF0 = 30;
    }

    if (this->fadeInState == DAYTELOP_HOURSTEXT_FADEIN) {
        this->alpha += (s16)(ABS_ALT(this->alpha - 255) / ref_D_80815FF0);

        ref_D_80815FF0--;
        if (ref_D_80815FF0 == 0) {
            this->fadeInState = DAYTELOP_HOURSTEXT_ON;
            this->alpha = 255;
        }
    }
}
