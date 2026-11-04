// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

void DynaPoly_UpdateContext(PlayState* play, DynaCollisionContext* dyna) {
    DynaPolyActor* actor;
    s32 vtxStartIndex;
    s32 polyStartIndex;
    s32 waterBoxStartIndex;
    s32 i;

    DynaSSNodeList_ResetCount(&dyna->polyNodes);

    for (i = 0; i < BG_ACTOR_MAX; i++) {
        DynaLookup_ResetLists(&dyna->bgActors[i].dynaLookup);
    }

    for (i = 0; i < BG_ACTOR_MAX; i++) {
        if (dyna->bgActorFlags[i] & BGACTOR_1) {
            
            dyna->bgActorFlags[i] = 0;
            BgActor_Init(play, &dyna->bgActors[i]);
            dyna->bitFlag |= DYNAPOLY_INVALIDATE_LOOKUP;
        }
        if ((dyna->bgActors[i].actor != NULL) && (dyna->bgActors[i].actor->update == NULL)) {
            
            actor = DynaPoly_GetActor(&play->colCtx, i);
            if (actor == NULL) {
                return;
            }
            actor->bgId = BGACTOR_NEG_ONE;
            dyna->bgActorFlags[i] = 0;

            BgActor_Init(play, &dyna->bgActors[i]);
            dyna->bitFlag |= DYNAPOLY_INVALIDATE_LOOKUP;
        }
    }
    vtxStartIndex = 0;
    polyStartIndex = 0;
    waterBoxStartIndex = 0;
    for (i = 0; i < BG_ACTOR_MAX; i++) {
        if ((dyna->bgActorFlags[i] & BGACTOR_IN_USE) && !(dyna->bgActorFlags[i] & BGACTOR_1)) {
            DynaPoly_AddBgActorToLookup(play, dyna, i, &vtxStartIndex, &polyStartIndex, &waterBoxStartIndex);
        }
    }
    dyna->bitFlag &= ~DYNAPOLY_INVALIDATE_LOOKUP;
}
