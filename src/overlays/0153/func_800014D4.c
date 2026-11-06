// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_809381C4(ObjBean* this, PlayState* play) {
    this->unk_1E8(this);

    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        if (this->dyna.actor.csId > CS_ID_NONE) {
            Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_1);
        }
        this->unk_1E4 = 2;
        ref_func_80938284(this);
    } else if (this->unk_1E4 == 4) {
        CutsceneManager_Stop(this->dyna.actor.csId);
        Audio_PlaySfx(NA_SE_SY_ERROR);
        this->unk_1E4 = 0;
        ref_func_80937FB0(this);
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
