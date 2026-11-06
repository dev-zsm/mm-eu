// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B9B30(DoorWarp1* this, PlayState* play) {
    if (fabsf(this->dyna.actor.xzDistToPlayer) >= 60.0f) {
        if (DoorWarp1_GetRemains(this, play) != DOORWARP1_REMAINS_NONE) {
            this->unk_1A0 = (DmHina*)Actor_SpawnAsChild(
                &play->actorCtx, &this->dyna.actor, play, ACTOR_DM_HINA, this->dyna.actor.world.pos.x,
                this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z, 0, 0, 0,
                (DoorWarp1_GetRemains(this, play) - DOORWARP1_REMAINS_ODOLWA) + DMHINA_REMAINS_ODOLWA);
        }
        DoorWarp1_SetupAction(this, ref_func_808B9BE8);
    }
}
