// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mm.h"

void ref_func_80965D3C(EnMm* this, PlayState* play) {
    s16 csId = CutsceneManager_GetAdditionalCsId(this->actor.csId);

    if (CutsceneManager_IsNext(csId)) {
        CutsceneManager_StartWithPlayerCs(csId, &this->actor);
        EnMm_SetupAction(this, ref_func_80965DB4);
    } else {
        CutsceneManager_Queue(csId);
    }
}
