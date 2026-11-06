// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void ref_func_80A2A128(BgDblueMovebg* this, PlayState* play) {
    Actor* actorIter = NULL;

    while (true) {
        actorIter = SubS_FindActor(play, actorIter, ACTORCAT_BG, ACTOR_OBJ_HUNSUI);
        if (actorIter != NULL) {
            if ((OBJHUNSUI_GET_F000(actorIter) == 5) && (actorIter->update != NULL)) {
                this->unk_2F8[1] = actorIter;
            } else if ((OBJHUNSUI_GET_F000(actorIter) == 6) && (actorIter->update != NULL)) {
                this->unk_2F8[0] = actorIter;
            }
            actorIter = actorIter->next;
        }

        if (actorIter == NULL) {
            break;
        }
    }
}
