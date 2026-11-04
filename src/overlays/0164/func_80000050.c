// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_blockstop.h"

void ObjBlockstop_CheckForBlock(ObjBlockstop* this, PlayState* play) {
    Actor* prop = play->actorCtx.actorLists[ACTORCAT_PROP].first;

    while (prop != NULL) {
        if ((prop->id == ACTOR_OBJ_OSHIHIKI) && (fabsf(prop->world.pos.x - this->actor.world.pos.x) < 20.0f) &&
            (fabsf(prop->world.pos.z - this->actor.world.pos.z) < 20.0f) &&
            (fabsf(prop->world.pos.y - this->actor.world.pos.y) < 20.0f)) {

            s32 params = OBJOSHIHIKI_GET_F(prop);
            if (params < 3) {
                CutsceneManager_Queue(this->actor.csId);
                this->actionFunc = ObjBlockstop_TryPlayCutscene;
            }
        }
        prop = prop->next;
    }
}
