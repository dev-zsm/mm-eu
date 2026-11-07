// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_estone.h"

void EnEstone_Active(EnEstone* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f accel;
    Vec3f velocity;
    s32 i;

    if ((this->actor.floorHeight == -10000.0f) || ((player->actor.world.pos.y - 200.0f) > this->actor.world.pos.y)) {
        Actor_Kill(&this->actor);
        return;
    }
    if (((this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) && (this->actor.velocity.y < 0.0f)) ||
        (this->collider.base.atFlags & AT_BOUNCED)) {
        this->collider.base.atFlags &= ~AT_BOUNCED;
        if (this->actor.params == ENESTONE_TYPE_LARGE) {
            for (i = 0; i < 2; i++) {
                accel.x = 2.0f * (Rand_ZeroOne() - 0.5f);
                accel.y = -1.0f;
                accel.z = 2.0f * (Rand_ZeroOne() - 0.5f);
                velocity.x = 3.0f * (Rand_ZeroOne() - 0.5f);
                velocity.y = 5.0f + (Rand_ZeroOne() * 10.0f);
                velocity.z = 3.0f * (Rand_ZeroOne() - 0.5f);
                EnEstone_SpawnEffect(this, &this->actor.world.pos, &velocity, &accel,
                                     0.003f + (0.002f * Rand_ZeroFloat(1.0f)), 20);
            }
        }
        Math_Vec3f_Copy(&velocity, &this->actor.world.pos);
        velocity.y = this->actor.floorHeight;
        Actor_SpawnFloorDustRing(play, &this->actor, &velocity, 0.0f, 10, 6.0f, 50, 30, true);
        this->actor.velocity.y = this->actor.gravity = 0.0f;
        this->actor.speed *= 0.3f;
        this->actor.shape.shadowScale = 0.0f;
        this->inactive = true;
        this->timer = 50;
        Actor_PlaySfx(&this->actor, NA_SE_EV_WALL_BROKEN);
        this->actionFunc = EnEstone_Inactive;
    } else {
        
    label:
        this->actor.shape.shadowScale = 4500.0f * this->scale;
        Actor_SetScale(&this->actor, this->scale);
    }
}
