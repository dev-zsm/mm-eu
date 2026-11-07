// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kujiya.h"

void EnKujiya_TurnToOpen(EnKujiya* this, PlayState* play) {
    if (this->actor.csId != CS_ID_NONE) {
        if (CutsceneManager_IsNext(this->actor.csId)) {
            CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        } else {
            CutsceneManager_Queue(this->actor.csId);
        }
    }

    if (!Math_SmoothStepToS(&this->actor.shape.rot.y, 0x7555, 0xA, 0x16C, 0x16C)) {
        if (this->timer > 20) {
            if (CutsceneManager_GetCurrentCsId() == this->actor.csId) {
                CutsceneManager_Stop(this->actor.csId);
            }
            EnKujiya_SetupWait(this);
        } else {
            this->timer++;
        }
    } else {
        Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_WINDMILL_LEVEL - SFX_FLAG);
    }
}
