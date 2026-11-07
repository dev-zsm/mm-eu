// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_ExteriorGear_Init(ObjTokeidai* this, PlayState* play) {
    this->actor.draw = ObjTokeidai_ExteriorGear_Draw;
    this->opaDList = gClockTowerExteriorGearDL;
    ObjTokeidai_SetupClockOrExteriorGear(this);

    if (((play->sceneId == SCENE_CLOCKTOWER) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0)) ||
        ((play->sceneId == SCENE_00KEIKOKU) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0))) {
        ObjTokeidai_SetupTowerOpening(this);
    } else if (((CURRENT_DAY == 3) && (CURRENT_TIME < CLOCK_TIME(6, 0))) || (CURRENT_DAY >= 4)) {
        this->actionFunc = ObjTokeidai_ExteriorGear_OpenedIdle;
        this->actor.world.pos.y += this->actor.scale.y * 1900.0f;
        this->actor.shape.yOffset = 1500.0f;
        SET_WEEKEVENTREG(WEEKEVENTREG_CLOCK_TOWER_OPENED);
    } else {
        this->actionFunc = ObjTokeidai_ExteriorGear_Idle;
    }
}
