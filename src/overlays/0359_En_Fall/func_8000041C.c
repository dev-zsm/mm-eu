// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

Actor* EnFall_MoonsTear_GetTerminaFieldMoon(PlayState* play) {
    Actor* itemAction = play->actorCtx.actorLists[ACTORCAT_ITEMACTION].first;

    while (itemAction != NULL) {
        if (itemAction->id == ACTOR_EN_FALL && EN_FALL_TYPE(itemAction) == EN_FALL_TYPE_TERMINA_FIELD_MOON) {
            return itemAction;
        }
        itemAction = itemAction->next;
    }
    return NULL;
}
