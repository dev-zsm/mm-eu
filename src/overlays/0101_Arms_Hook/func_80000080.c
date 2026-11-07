// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_arms_hook.h"

void ArmsHook_Destroy(Actor* thisx, PlayState* play) {
    ArmsHook* this = (ArmsHook*)thisx;

    if (this->attachedActor != NULL) {
        this->attachedActor->flags &= ~ACTOR_FLAG_HOOKSHOT_ATTACHED;
    }
    Collider_DestroyQuad(play, &this->collider);
}
