// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_SetupPostSongLearnDialogue), score 2.00 (2 differ, size +1)
#include "generated/mm/z_en_kakasi.h"

void func_80001430(EnKakasi* this, PlayState* play) {
    CutsceneManager_Stop(this->csIdList[0]);
    play->msgCtx.ocarinaMode = OCARINA_MODE_END;
    this->unk190 = 0;
    this->unkCounter1A4 = 0;
    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_HOPPING_REGULAR);
    this->subCamId = SUB_CAM_ID_DONE;
    this->talkState = TEXT_STATE_EVENT;
    this->unkState1A8 = 1;
    this->actionFunc = EnKakasi_PostSongLearnDialogue;
    this->subCamFov = 0.0f;
    this->subCamFovNext = 60.0f;
}
