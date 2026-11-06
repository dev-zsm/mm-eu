// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_tag.h"

void EnWarpTag_WaitForPlayer(EnWarptag* this, PlayState* play) {
    if (!Player_InCsMode(play) && (this->dyna.actor.xzDistToPlayer <= 30.0f) &&
        (this->dyna.actor.playerHeightRel <= 10.0f)) {
        if (WARPTAG_GET_INVISIBLE(&this->dyna.actor)) {
            Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_81);
            this->actionFunc = EnWarpTag_GrottoReturn;
        } else {
            Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_15);
            this->actionFunc = EnWarpTag_RespawnPlayer;
        }
    }
}
