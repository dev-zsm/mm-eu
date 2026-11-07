// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_goron_oyu.h"

void ref_func_80B401F8(BgGoronOyu* this, PlayState* play) {
    Player* player;
    Vec3f dist;

    if (Actor_HasParent(&this->dyna.actor, play)) {
        this->dyna.actor.parent = NULL;
        return;
    }

    player = GET_PLAYER(play);
    Math_Vec3f_DistXYZAndStoreDiff(&this->waterBoxPos, &player->actor.world.pos, &dist);

    if ((dist.x >= 0.0f) && (dist.x <= this->waterBoxXLength) && (dist.z >= 0.0f) &&
        (dist.z <= this->waterBoxZLength) && (fabsf(dist.y) < 100.0f) && (player->actor.depthInWater > 12.0f)) {
        Actor_OfferGetItem(&this->dyna.actor, play, GI_MAX, this->dyna.actor.xzDistToPlayer,
                           fabsf(this->dyna.actor.playerHeightRel));
    }
}
