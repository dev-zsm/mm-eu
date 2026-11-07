// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_SpawnIceBlock(EnSlime* this, PlayState* play) {
    s32 stepCheck;

    stepCheck = Math_StepToF(&this->actor.world.pos.x, this->iceBlockSnapPos.x, 10.0f);
    stepCheck &= Math_StepToF(&this->actor.world.pos.z, this->iceBlockSnapPos.z, 10.0f);

    this->actor.colorFilterTimer = 10;
    if (stepCheck) {
        this->actor.child =
            Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_OBJ_ICEBLOCK, this->actor.world.pos.x,
                               this->actor.world.pos.y + 30.0f, this->actor.world.pos.z, 0, 0, 0, 0);
        if (this->actor.child != NULL) {
            this->actor.child->csId = this->actor.csId;
            EnSlime_SetupIceBlock(this);
        } else {
            this->actor.colorFilterTimer = 0;
            this->collider.base.acFlags |= AC_ON;
            this->iceBlockTimer = ICE_BLOCK_UNUSED;
            this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
            this->actor.gravity = -2.0f;
            EnSlime_SetupIdle(this);
        }
    }
}
