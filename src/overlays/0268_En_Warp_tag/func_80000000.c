// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_tag.h"

void EnWarptag_Init(Actor* thisx, PlayState* play) {
    EnWarptag* this = (EnWarptag*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    Actor_SetFocus(&this->dyna.actor, 0.0f);

    if (WARPTAG_GET_3C0_MAX(thisx) == WARPTAG_3C0_MAX) {
        this->dyna.actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;

        if (WARPTAG_GET_INVISIBLE(&this->dyna.actor)) {
            this->actionFunc = EnWarpTag_WaitForPlayer;

        } else {
            if ((this->dangeonKeepObjectSlot = Object_GetSlot(&play->objectCtx, GAMEPLAY_DANGEON_KEEP)) <=
                OBJECT_SLOT_NONE) {
                Actor_Kill(&this->dyna.actor);
            }

            this->actionFunc = EnWarpTag_CheckDungeonKeepObject;
        }

    } else { 
        this->actionFunc = EnWarpTag_Unused809C09A0;
    }
}
