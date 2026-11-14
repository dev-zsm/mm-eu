// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_SetupRiseOutOfGround), score 0.00 (0 differ, size +0)
#include "generated/mm/z_en_kakasi.h"

void func_8000227C(EnKakasi* this, PlayState* play) {
    s32 csIdIndex;

    csIdIndex = 0;
    if (this->aboveGroundStatus == ENKAKASI_ABOVE_GROUND_TYPE) {
        csIdIndex = 1;
    }

    if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
        CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
        CutsceneManager_Queue(this->csIdList[csIdIndex]);
    } else if (!CutsceneManager_IsNext(this->csIdList[csIdIndex])) {
        CutsceneManager_Queue(this->csIdList[csIdIndex]);
    } else {
        CutsceneManager_StartWithPlayerCs(this->csIdList[csIdIndex], &this->picto.actor);
        Actor_PlaySfx(&this->picto.actor, NA_SE_EN_AKINDONUTS_HIDE);
        this->picto.actor.draw = EnKakasi_Draw;
        this->unkState196 = 6;
        this->actionFunc = EnKakasi_RisingOutOfGround;
    }
}
