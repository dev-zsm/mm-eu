// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_nimotsu.h"

void EnNimotsu_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    EnNimotsu* this = (EnNimotsu*)thisx;
    Vec3f dustPosition;

    Actor_MoveWithGravity(&this->actor);

    if (!(this->dustDone & 1) && (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND)) {
        if (DECR(this->timer) == 0) {
            this->dustDone |= 1;
        }

        if ((play->state.frames % 3) == 0) {
            dustPosition.x = this->actor.world.pos.x + Rand_CenteredFloat(15.0f);
            dustPosition.y = this->actor.world.pos.y;
            dustPosition.z = this->actor.world.pos.z + Rand_CenteredFloat(15.0f);
            Actor_SpawnFloorDustRing(play, &this->actor, &dustPosition, 20.0f, 0, 2.0f, 0, 0, false);
        }
    }

    EnNimotsu_UpdateCollision(this, play);
}
