// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

s32 ref_func_808B866C(DoorWarp1* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 ret = false;

    if ((fabsf(this->dyna.actor.xzDistToPlayer) < 60.0f) &&
        (((player->actor.world.pos.y - 20.0f) < this->dyna.actor.world.pos.y) &&
         (this->dyna.actor.world.pos.y < (player->actor.world.pos.y + 20.0f)))) {
        ret = true;
    }
    return ret;
}
