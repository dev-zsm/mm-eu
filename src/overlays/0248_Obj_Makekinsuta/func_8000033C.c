// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_makekinsuta.h"

void ref_func_8099FD7C(Actor* thisx, PlayState* play) {
    if (CutsceneManager_IsNext(thisx->csId)) {
        CutsceneManager_StartWithPlayerCs(thisx->csId, thisx);
        if (thisx->csId > CS_ID_NONE) {
            Player_SetCsActionWithHaltedActors(play, thisx, PLAYER_CSACTION_4);
        }
        ref_func_8099FB64(thisx, play);
        thisx->update = Actor_Noop;
        thisx->flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
    } else {
        CutsceneManager_Queue(thisx->csId);
    }
}
