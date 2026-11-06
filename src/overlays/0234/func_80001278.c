// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_comb.h"

void ref_func_8098E0B8(ObjComb* this, PlayState* play) {
    this->unk_1B4--;
    if (this->unk_1B4 <= 0) {
        Actor_Kill(&this->actor);
        return;
    }

    if ((this->unk_1B4 == 10) && (this->unk_1B6 != 0) && (this->unk_1B5 == 2) && (this->actor.csId > CS_ID_NONE)) {
        if (CutsceneManager_GetCurrentCsId() == this->actor.csId) {
            Player_SetCsActionWithHaltedActors(play, &this->actor, PLAYER_CSACTION_4);
        }
    }
}
