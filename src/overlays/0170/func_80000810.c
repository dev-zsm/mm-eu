// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ingate.h"

void ref_func_809542A0(BgIngate* this, PlayState* play) {
    if (CHECK_EVENTINF(EVENTINF_50)) {
        play->nextEntrance = ENTRANCE(TOURIST_INFORMATION, 2);
        CLEAR_EVENTINF(EVENTINF_50);
    } else {
        play->nextEntrance = ENTRANCE(TOURIST_INFORMATION, 1);
    }
    gSaveContext.nextCutsceneIndex = 0;
    play->transitionTrigger = TRANS_TRIGGER_START;
    play->transitionType = TRANS_TYPE_FADE_WHITE;
    gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
    this->actionFunc = ref_func_80953F8C;
    CLEAR_WEEKEVENTREG(WEEKEVENTREG_90_40);
    Environment_StartTime();
}
