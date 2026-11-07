// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_IceBlockThaw(EnSlime* this, PlayState* play) {
    s32 iceBlockTimerAdj;

    this->actor.colorFilterTimer = 10;
    if ((this->actor.child != NULL) && (this->actor.child->update != NULL)) {
        iceBlockTimerAdj = (0.1f - this->actor.child->scale.y) * 10.0f * 255.0f;
        this->iceBlockTimer = CLAMP(iceBlockTimerAdj, 0, ICE_BLOCK_UNUSED);
    } else {
        this->actor.child = NULL;
        iceBlockTimerAdj = this->iceBlockTimer + 10;
        this->iceBlockTimer = CLAMP_MAX(iceBlockTimerAdj, ICE_BLOCK_UNUSED);
    }

    if (this->iceBlockTimer == ICE_BLOCK_UNUSED) {
        this->collider.base.acFlags |= AC_ON;
        this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
        this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        EnSlime_SetupIdle(this);
    }
}
