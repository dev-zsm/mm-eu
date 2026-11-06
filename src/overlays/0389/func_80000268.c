// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_TowerClock_Init(ObjTokeidai* this, PlayState* play) {
    this->actor.draw = ObjTokeidai_Clock_Draw;
    ObjTokeidai_Clock_Init(this);

    if (((play->sceneId == SCENE_CLOCKTOWER) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0)) ||
        ((play->sceneId == SCENE_00KEIKOKU) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0))) {
        ObjTokeidai_SetupTowerOpening(this);
    } else if (((CURRENT_DAY == 3) && (CURRENT_TIME < CLOCK_TIME(6, 0))) || (CURRENT_DAY >= 4)) {
        this->actor.world.pos.y += (this->actor.scale.y * 5191.0f) - 50.0f;
        this->actor.world.pos.x += Math_SinS(this->actor.world.rot.y) * this->actor.scale.z * 1791.0f;
        this->actor.world.pos.z += -Math_CosS(this->actor.world.rot.y) * this->actor.scale.z * 1791.0f;

        this->clockFaceZTranslation = -0x140;
        this->actor.shape.rot.x = -0x4000;

        this->actor.home.pos = this->actor.world.pos;
        this->actor.home.pos.y -= 1178.0f;
        this->actor.home.pos.z += 13.0f;

        this->actionFunc = ObjTokeidai_TowerClock_OpenedIdle;
    } else {
        this->actionFunc = ObjTokeidai_TowerClock_Idle;
    }
}
