// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_DancingRemark), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_kakasi.h"

void func_80001940(EnKakasi* this, PlayState* play) {
    u32 currentDay = gSaveContext.save.day;

    this->unkState196 = 3;
    if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
        CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
        CutsceneManager_Queue(this->csIdList[0]);
    } else if (!CutsceneManager_IsNext(this->csIdList[0])) {
        CutsceneManager_Queue(this->csIdList[0]);
    } else {
        CutsceneManager_StartWithPlayerCs(this->csIdList[0], &this->picto.actor);
        this->subCamId = CutsceneManager_GetCurrentSubCamId(this->picto.actor.csId);
        if ((currentDay == 3) && gSaveContext.save.isNight) {
            EnKakasi_SetupDigAway(this);
        } else {
            Audio_PlaySubBgm(NA_BGM_SARIAS_SONG);
            EnKakasi_SetupDanceNightAway(this);
        }
    }
}
