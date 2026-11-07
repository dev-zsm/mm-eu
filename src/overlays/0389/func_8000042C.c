// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_Counterweight_Init(ObjTokeidai* this, PlayState* play) {
    s32 type;

    this->actor.draw = ObjTokeidai_Counterweight_Draw;
    this->opaDList = gClockTowerCounterweightDL;
    this->xluDList = gClockTowerSpotlightDL;
    if (gSaveContext.save.isNight) {
        this->spotlightIntensity = 100;
    } else {
        this->spotlightIntensity = 0;
    }

    if (((play->sceneId == SCENE_CLOCKTOWER) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0)) ||
        ((play->sceneId == SCENE_00KEIKOKU) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0))) {
        this->spotlightIntensity = 0;
        ObjTokeidai_SetupTowerOpening(this);

        if (this->actor.child == NULL) {
            type = OBJ_TOKEIDAI_TYPE(&this->actor);
            if ((type == OBJ_TOKEIDAI_TYPE_COUNTERWEIGHT_CLOCK_TOWN) ||
                (type == OBJ_TOKEIDAI_TYPE_COUNTERWEIGHT_TERMINA_FIELD)) {
                this->actor.child = Actor_Spawn(&play->actorCtx, play, ACTOR_EN_HANABI, this->actor.world.pos.x,
                                                this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, 0);
            }
        }

        if (this->actor.child != NULL) {
            if (OBJ_TOKEIDAI_TYPE(&this->actor) == OBJ_TOKEIDAI_TYPE_COUNTERWEIGHT_TERMINA_FIELD) {
                this->actor.child->home.rot.x = 0x384;
            } else {
                this->actor.child->home.rot.x = 0x12C;
            }
        }
    } else if (((CURRENT_DAY == 3) && (CURRENT_TIME < CLOCK_TIME(6, 0))) || (CURRENT_DAY >= 4)) {
        this->spotlightIntensity = 0;
        this->actor.world.pos.y += this->actor.scale.y * -2160.0f;
        this->actor.world.pos.x += Math_SinS(this->actor.world.rot.y) * this->actor.scale.z * 5400.0f;
        this->actor.world.pos.z += -Math_CosS(this->actor.world.rot.y) * this->actor.scale.z * 5400.0f;
        this->actor.shape.rot.x = -0x4000;
        this->actionFunc = ObjTokeidai_Counterweight_OpenedIdle;
    } else {
        this->actionFunc = ObjTokeidai_Counterweight_Idle;
    }
}
