// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_SetupSpawnIceBlock(EnSlime* this) {
    this->collider.base.acFlags &= ~AC_ON;
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    this->drawDmgEffAlpha = 0.0f;
    this->actor.speed = 0.0f;
    this->actor.velocity.y = 0.0f;
    this->actor.gravity = 0.0f;
    this->iceBlockSnapPos.x = EnSlime_SnapIceBlockPosition(this->actor.world.pos.x, this->actor.home.pos.x);
    this->iceBlockSnapPos.z = EnSlime_SnapIceBlockPosition(this->actor.world.pos.z, this->actor.home.pos.z);
    Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_GRAY, COLORFILTER_INTENSITY_FLAG | 255,
                         COLORFILTER_BUFFLAG_XLU, 10);
    this->eyeTexIndex = EN_SLIME_EYETEX_OPEN;
    this->iceBlockTimer = ICE_BLOCK_TIMER_MAX;
    this->actionFunc = EnSlime_SpawnIceBlock;
}
