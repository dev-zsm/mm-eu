// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

s32 ref_func_80BA2708(ObjNozoki* this, PlayState* play) {
    Actor* enemy = play->actorCtx.actorLists[ACTORCAT_ENEMY].first;
    Vec3f sp30;

    while (enemy != NULL) {
        Actor_WorldToActorCoords(&this->dyna.actor, &sp30, &enemy->world.pos);
        if (sp30.z >= 0.0f) {
            return false;
        }
        enemy = enemy->next;
    }

    return true;
}
