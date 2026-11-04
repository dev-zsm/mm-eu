// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 DynaPoly_SetBgActor(PlayState* play, DynaCollisionContext* dyna, Actor* actor, CollisionHeader* colHeader) {
    s32 bgId;
    s32 foundSlot = false;

    for (bgId = 0; bgId < BG_ACTOR_MAX; bgId++) {
        if (!(dyna->bgActorFlags[bgId] & BGACTOR_IN_USE)) {
            dyna->bgActorFlags[bgId] |= BGACTOR_IN_USE;
            foundSlot = true;
            break;
        }
    }

    if (foundSlot == false) {
        return BG_ACTOR_MAX;
    }

    BgActor_SetActor(&dyna->bgActors[bgId], actor, colHeader);
    dyna->bitFlag |= DYNAPOLY_INVALIDATE_LOOKUP;

    dyna->bgActorFlags[bgId] &= ~BGACTOR_1;
    return bgId;
}
