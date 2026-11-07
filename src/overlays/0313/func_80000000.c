// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_Init(Actor* thisx, PlayState* play) {
    EnSlime* this = (EnSlime*)thisx;
    s32 reviveTimeSeconds;
    s32 i;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitAndSetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    CollisionCheck_SetInfo(&this->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 38.0f);

    this->iceBlockTimer = ICE_BLOCK_UNUSED;
    this->eyeTexIndex = EN_SLIME_EYETEX_OPEN;
    this->wobbleRot.y = 0.0f;

    
    if (this->actor.shape.rot.x <= 0) {
        this->distLimit = 30000.0f;
    } else {
        this->distLimit = this->actor.shape.rot.x * 40.0f;
    }

    this->actor.shape.rot.x = 0;
    reviveTimeSeconds = EN_SLIME_GET_REVIVE_TIME(&this->actor);
    this->actor.shape.rot.z = 0;
    this->actor.params &= 0xFF;
    if (reviveTimeSeconds == 0xFF) {
        reviveTimeSeconds = 0;
    }

    
    this->reviveTime = (reviveTimeSeconds * 20) + 200;

    
    if (!sTexturesDesegmented) {
        for (i = 0; i < EN_SLIME_EYETEX_MAX; i++) {
            sEyeTextures[i] = Lib_SegmentedToVirtual(sEyeTextures[i]);
        }
        sSlimeTexAnim = Lib_SegmentedToVirtual(gChuchuSlimeFlowTexAnim);
        sTexturesDesegmented = true;
    }

    
    if (EN_SLIME_GET_TYPE(&this->actor) == EN_SLIME_TYPE_YELLOW) {
        this->itemDropTex = Lib_SegmentedToVirtual(gDropArrows1Tex);
        this->actor.hintId = TATL_HINT_ID_YELLOW_CHUCHU;
    } else if (EN_SLIME_GET_TYPE(&this->actor) == EN_SLIME_TYPE_GREEN) {
        this->itemDropTex = Lib_SegmentedToVirtual(gDropMagicSmallTex);
        this->actor.hintId = TATL_HINT_ID_GREEN_CHUCHU;
    } else if (EN_SLIME_GET_TYPE(&this->actor) == EN_SLIME_TYPE_RED) {
        this->itemDropTex = Lib_SegmentedToVirtual(gDropRecoveryHeartTex);
        this->actor.hintId = TATL_HINT_ID_RED_CHUCHU;
    } else {
        this->actor.hintId = TATL_HINT_ID_BLUE_CHUCHU;
    }

    
    EnSlime_SetupInitializeIdle(this);
}
