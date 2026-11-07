// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ctower_gear.h"

void BgCtowerGear_UpdateOrgan(Actor* thisx, PlayState* play) {
    BgCtowerGear* this = (BgCtowerGear*)thisx;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_104)) {
        switch (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_104)]->id) {
            case 1:
                this->dyna.actor.draw = NULL;
                DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
                break;

            case 2:
                this->dyna.actor.draw = BgCtowerGear_DrawOrgan;
                DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
                break;

            case 3:
                Actor_Kill(&this->dyna.actor);
                break;

            default:
                break;
        }
    }
}
