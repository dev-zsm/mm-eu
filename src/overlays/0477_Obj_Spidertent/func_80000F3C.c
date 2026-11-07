// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

void ref_func_80B30A4C(ObjSpidertent* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        if (this->dyna.actor.csId > CS_ID_NONE) {
            Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_1);
        }
        Flags_SetSwitch(play, OBJSPIDERTENT_GET_SWITCH_FLAG(&this->dyna.actor));
        ref_func_80B30AD4(this);
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
