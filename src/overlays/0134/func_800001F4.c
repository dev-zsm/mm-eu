// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_umajump.h"

void BgUmajump_Init(Actor* thisx, PlayState* play) {
    BgUmajump* this = (BgUmajump*)thisx;

    Actor_ProcessInitChain(thisx, sInitChain);

    this->actionFunc = NULL;
    this->horse = NULL;
    this->hasSoundPlayed = false;

    DynaPolyActor_Init(&this->dyna, 0);

    this->pathIndex = BG_UMAJUMP_GET_PATH_INDEX(thisx);
    thisx->params = BG_UMAJUMP_GET_TYPE(thisx);

    if (thisx->params == BG_UMAJUMP_TYPE_2) {
        if ((play->sceneId == SCENE_F01) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_89_20) &&
            !CHECK_QUEST_ITEM(QUEST_SONG_EPONA) && (thisx->csId != CS_ID_NONE)) {
            this->actionFunc = BgUmajump_CheckDistance;
            thisx->update = ref_func_8091A5A0;
            thisx->flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
            this->horse = SubS_FindActor(play, this->horse, ACTORCAT_BG, ACTOR_EN_HORSE);
        } else {
            thisx->update = Actor_Noop;
        }
    } else {
        this->objectSlot = Object_GetSlot(&play->objectCtx, OBJECT_UMAJUMP);

        if (this->objectSlot <= OBJECT_SLOT_NONE) {
            Actor_Kill(thisx);
        }

        if ((thisx->params == BG_UMAJUMP_TYPE_3) && CHECK_QUEST_ITEM(QUEST_SONG_EPONA)) {
            Actor_Spawn(&play->actorCtx, play, ACTOR_EN_KANBAN, thisx->world.pos.x, thisx->world.pos.y,
                        thisx->world.pos.z, thisx->shape.rot.x, thisx->shape.rot.y, thisx->shape.rot.z, 0x3E);
            Actor_Kill(thisx);
        }
    }
}
