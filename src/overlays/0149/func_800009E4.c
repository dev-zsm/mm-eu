// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tubo_trap.h"

void EnTuboTrap_FlyAtPlayer(EnTuboTrap* this, PlayState* play) {
    f32 dX = this->originPos.x - this->actor.world.pos.x;
    f32 dY = this->originPos.y - this->actor.world.pos.y;
    f32 dZ = this->originPos.z - this->actor.world.pos.z;

    
    
    
    
    
    
    Actor_PlaySfx(&this->actor, NA_SE_EN_MIZUBABA2_ATTACK - SFX_FLAG);

    if ((SQ(dX) + SQ(dY) + SQ(dZ) > SQ(240.0f))) {
        Math_ApproachF(&this->actor.gravity, -3.0f, 0.2f, 0.5f);
    }

    this->actor.shape.rot.y += 0x1388;
    EnTuboTrap_HandleImpact(this, play);
}
