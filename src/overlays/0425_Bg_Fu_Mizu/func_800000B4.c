// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_fu_mizu.h"

s32 ref_func_80ADABA4(BgFuMizu* this, PlayState* play) {
    Actor* actor = play->actorCtx.actorLists[ACTORCAT_BG].first;

    while (actor != NULL) {
        if ((actor != NULL) && (actor->id == ACTOR_EN_FU_KAGO) && (actor->colChkInfo.health == 0)) {
            return false;
        }
        actor = actor->next;
    }

    return true;
}
