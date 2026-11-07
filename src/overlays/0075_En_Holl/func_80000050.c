// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_SetPlayerSide(PlayState* play, EnHoll* this, Vec3f* transformedPlayerPos) {
    Player* player = GET_PLAYER(play);

    Actor_WorldToActorCoords(&this->actor, transformedPlayerPos, &player->actor.world.pos);
    this->playerSide = (transformedPlayerPos->z < 0.0f) ? EN_HOLL_BEHIND : EN_HOLL_BEFORE;
}
