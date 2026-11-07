// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test5.h"

void EnTest5_HandleBottleAction(EnTest5* this, PlayState* play) {
    Player* player;
    Vec3f playerPosRelativeToWater;

    if (Actor_HasParent(&this->actor, play)) {
        this->actor.parent = NULL;
        return;
    }

    player = GET_PLAYER(play);

    if ((player->interactRangeActor == NULL) || (player->getItemId != GI_MAX)) {
        Math_Vec3f_DistXYZAndStoreDiff(&this->minPos, &player->actor.world.pos, &playerPosRelativeToWater);

        
        if ((playerPosRelativeToWater.x >= 0.0f) && (playerPosRelativeToWater.x <= this->xLength) &&
            (playerPosRelativeToWater.z >= 0.0f) && (playerPosRelativeToWater.z <= this->zLength) &&
            (fabsf(playerPosRelativeToWater.y) < 100.0f) && (player->actor.depthInWater > 12.0f)) {
            Actor_OfferGetItem(&this->actor, play, GI_MAX, this->actor.xzDistToPlayer,
                               fabsf(this->actor.playerHeightRel));
        }
    }
}
