// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure2.h"

void ObjMure2_SpawnChildren(ObjMure2* this, PlayState* play) {
    Vec3f* pos;
    Mure2ChildType childType = OBJ_MURE2_GET_CHILD_TYPE(&this->actor);
    Vec3f spawnPos[OBJ_MURE2_CHILD_MAX];
    s16 childParams;
    s32 i;

    sSpawnPosFuncs[childType](spawnPos, this);
    ObjMure2_GetChildParams(&childParams, this);
    for (i = 0; i < sChildCounts[childType]; i++) {
        if (this->actors[i] != NULL) {
            continue;
        }
        if (((this->spawnFlags >> i) & 1) == 0) {
            pos = &spawnPos[i];
            this->actors[i] = Actor_SpawnAsChildAndCutscene(
                &play->actorCtx, play, sActorIds[childType], pos->x, pos->y, pos->z, this->actor.world.rot.x, 0,
                this->actor.world.rot.z, childParams, this->actor.csId, this->actor.halfDaysBits, NULL);
            if (this->actors[i] != NULL) {
                this->actors[i]->room = this->actor.room;
            }
        }
    }
}
