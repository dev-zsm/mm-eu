// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_wturn.h"

void ObjWturn_FallingCs(ObjWturn* this, PlayState* play) {
    static Vec3f sSubCamUp = { 0.0f, -1.0f, 0.0f };
    Camera* subCam = Play_GetCamera(play, this->subCamId);
    Player* player = GET_PLAYER(play);

    this->fallingFrame++;
    player->actor.world.pos.y = this->actor.world.pos.y + this->fallingFrame * 4.0f;
    Play_SetCameraAtEyeUp(play, this->subCamId, &player->actor.focus.pos, &subCam->eye, &sSubCamUp);
    if (this->fallingFrame == 1) {
        play->transitionType = TRANS_TYPE_64;
        gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
        gSaveContext.nextCutsceneIndex = 0;
        if (play->sceneId == SCENE_F40) {
            play->nextEntrance = ENTRANCE(STONE_TOWER_INVERTED, 0);
        } else {
            play->nextEntrance = ENTRANCE(STONE_TOWER, 1);
        }
        play->transitionTrigger = TRANS_TRIGGER_START;
    }
}
