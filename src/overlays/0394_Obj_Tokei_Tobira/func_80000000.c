// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_tobira.h"

void ObjTokeiTobira_Init(Actor* thisx, PlayState* play) {
    ObjTokeiTobira* this = (ObjTokeiTobira*)thisx;
    s32 pad;
    s32 type = OBJTOKEITOBIRA_GET_TYPE(&this->dyna.actor);
    Vec3f posOffset;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS | DYNA_TRANSFORM_ROT_Y);
    DynaPolyActor_LoadMesh(play, &this->dyna, ref_D_80ABD770[type]);

    if (type == OBJTOKEITOBIRA_TYPE_0) {
        Actor_SpawnAsChild(&play->actorCtx, &this->dyna.actor, play, ACTOR_OBJ_TOKEI_TOBIRA,
                           this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                           this->dyna.actor.shape.rot.x, this->dyna.actor.shape.rot.y, this->dyna.actor.shape.rot.z,
                           OBJTOKEITOBIRA_PARAMS(OBJTOKEITOBIRA_TYPE_1));
    }

    Matrix_RotateYS(ref_D_80ABD76C[type] + this->dyna.actor.shape.rot.y, MTXMODE_NEW);
    Matrix_MultVec3f(&ref_D_80ABD760, &posOffset);
    this->dyna.actor.world.pos.x += posOffset.x;
    this->dyna.actor.world.pos.y += posOffset.y;
    this->dyna.actor.world.pos.z += posOffset.z;

    if ((type == OBJTOKEITOBIRA_TYPE_0) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_59_04) &&
        (play->sceneId == SCENE_CLOCKTOWER) && (gSaveContext.sceneLayer == 0) && (this->dyna.actor.csId > CS_ID_NONE)) {
        this->dyna.actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        this->actionFunc = ObjTokeiTobira_StartCutscene;
    }
}
