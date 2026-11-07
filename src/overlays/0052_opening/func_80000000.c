// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_opening.h"

void TitleSetup_SetupTitleScreen(TitleSetupState* this) {
    static s32 sOpeningEntrances[] = { ENTRANCE(CUTSCENE, 0), ENTRANCE(CUTSCENE, 1) };
    static s32 sOpeningCutscenes[] = { 0xFFFA, 0xFFFA };

    CLEAR_EVENTINF(EVENTINF_17);
    gSaveContext.gameMode = GAMEMODE_TITLE_SCREEN;

    Sram_InitNewSave();

    gSaveContext.save.entrance = sOpeningEntrances[gOpeningEntranceIndex];
    gSaveContext.nextCutsceneIndex = gSaveContext.save.cutsceneIndex = sOpeningCutscenes[gOpeningEntranceIndex];
    gSaveContext.sceneLayer = 0;

    gSaveContext.save.time = CLOCK_TIME(8, 0);
    gSaveContext.save.day = 1;

    STOP_GAMESTATE(&this->state);
    SET_NEXT_GAMESTATE(&this->state, Play_Init, sizeof(PlayState));

    gSaveContext.save.playerForm = PLAYER_FORM_HUMAN;
}
