// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_wturn.h"

void ObjWturn_SetupInversionCs(ObjWturn* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f subCamEye;
    Vec3f subCamAt;

    CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
    Play_EnableMotionBlur(140);
    this->subCamId = CutsceneManager_GetCurrentSubCamId(this->actor.csId);
    Player_SetCsActionWithHaltedActors(play, &this->actor, PLAYER_CSACTION_21);
    subCamAt.x = player->actor.focus.pos.x;
    subCamAt.z = player->actor.focus.pos.z;
    subCamAt.y = player->actor.focus.pos.y;
    subCamEye.x = (Math_SinS(this->actor.shape.rot.y) * 150.0f) + subCamAt.x;
    subCamEye.z = (Math_CosS(this->actor.shape.rot.y) * 150.0f) + subCamAt.z;
    subCamEye.y = subCamAt.y + 4.0f;
    Play_SetCameraAtEye(play, this->subCamId, &subCamAt, &subCamEye);
    this->actionFunc = ObjWturn_InversionCs;
}
