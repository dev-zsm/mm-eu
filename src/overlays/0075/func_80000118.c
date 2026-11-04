// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_Destroy(Actor* thisx, PlayState* play) {
    EnHoll* this = (EnHoll*)thisx;

    if (!EN_HOLL_IS_SCENE_CHANGER(this)) {
        u32 enHollId = EN_HOLL_GET_ID(&this->actor);

        play->transitionActors.list[enHollId].id = -play->transitionActors.list[enHollId].id;
        if (this == sInstancePlayingSound) {
            sInstancePlayingSound = NULL;
        }
    }
}
