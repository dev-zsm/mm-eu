// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnTest7* this = (EnTest7*)thisx;
    Player* player = GET_PLAYER(play);
    Player* player2 = GET_PLAYER(play);

    this->actor.world.rot.y = this->actor.shape.rot.y = player->actor.shape.rot.y;
    this->flags = 0;
    this->timer = 0;
    this->playerYaw = player->actor.shape.rot.y;
    this->playerScaleX = player->actor.scale.x;
    this->playerScaleZ = player->actor.scale.z;

    
    Keyframe_InitFlex(&this->kfSkelAnime, &gameplay_keep_KFSkel_085640, &gameplay_keep_KFAnim_083534, this->jointTable,
                      this->morphTable, NULL);
    Keyframe_FlexPlayOnce(&this->kfSkelAnime, &gameplay_keep_KFAnim_083534);

    EnTest7_InitFeathers(this->feathers);
    EnTest7_InitWindCapsule(&this->windCapsule);

    if (OWL_WARP_CS_GET_OCARINA_MODE(&this->actor) == ENTEST7_ARRIVE) {
        EnTest7_SetupAction(this, EnTest7_SetupArriveCs);
        EnTest7_SetupPlayerCamFunc(this, NULL);
    } else {
        EnTest7_SetupAction(this, EnTest7_StartWarpCs);
        EnTest7_SetupPlayerCamFunc(this, EnTest7_PlayerAndSubCamAction);
        Audio_PlayBgm_StorePrevBgm(NA_BGM_SONG_OF_SOARING);
    }

    if (play->playerCsIds[PLAYER_CS_ID_SONG_WARP] == CS_ID_NONE) {
        Actor_Kill(&this->actor);
        return;
    }

    CutsceneManager_Queue(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]);
    player2->stateFlags1 |= PLAYER_STATE1_20;
    Lights_PointNoGlowSetInfo(&this->lightInfo, (Math_SinS(this->playerYaw) * 90.0f) + player->actor.world.pos.x,
                              player->actor.world.pos.y + 10.0f,
                              (Math_CosS(this->playerYaw) * 90.0f) + player->actor.world.pos.z, 255, 255, 255, 255);
    this->lightNode = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo);
}
