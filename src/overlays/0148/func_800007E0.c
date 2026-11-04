// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_honotrap.h"

void EnHonotrap_EyeOpen(EnHonotrap* this, PlayState* play) {
    this->eyeState--;
    if (this->eyeState <= HONOTRAP_EYE_OPEN) {
        EnHonotrap_SetupEyeAttack(this);
        Actor_SpawnAsChild(
            &play->actorCtx, &this->actor, play, ACTOR_EN_HONOTRAP,
            (Math_SinS(this->actor.shape.rot.y) * 12.0f) + this->actor.home.pos.x, this->actor.home.pos.y - 10.0f,
            (Math_CosS(this->actor.shape.rot.y) * 12.0f) + this->actor.home.pos.z, this->actor.home.rot.x,
            this->actor.home.rot.y, this->actor.home.rot.z, HONOTRAP_TYPE_FLAME_MOVE);
    }
}
