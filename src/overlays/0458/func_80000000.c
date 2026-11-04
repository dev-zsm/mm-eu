// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_tobira01.h"

void BgTobira01_Action(BgTobira01* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s16 csId = this->dyna.actor.csId;
    s16 prevPosYTick;

    if (this->cutsceneRequested) {
        if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
            CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
        } else if (CutsceneManager_IsNext(csId)) {
            CutsceneManager_StartWithPlayerCs(csId, &this->dyna.actor);
            SET_WEEKEVENTREG(WEEKEVENTREG_GATEKEEPER_OPENED_GORON_SHRINE);
            this->cutsceneRequested = false;
        } else {
            CutsceneManager_Queue(csId);
        }
    } else if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_GATEKEEPER_OPENED_GORON_SHRINE) && (this->posYTick == 0) &&
               (play->actorCtx.playerImpact.timer != 0) &&
               (play->actorCtx.playerImpact.type == PLAYER_IMPACT_GORON_GROUND_POUND) &&
               (SurfaceType_GetSceneExitIndex(&play->colCtx, player->actor.floorPoly, player->actor.floorBgId) == 6)) {
        this->cutsceneRequested = true;
        this->unk16C = 0;
    }

    prevPosYTick = this->posYTick;
    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_GATEKEEPER_OPENED_GORON_SHRINE)) {
        this->posYTick++;
    } else {
        this->posYTick--;
    }

    this->posYTick = CLAMP(this->posYTick, 0, 60);
    if (prevPosYTick != this->posYTick) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_STONEDOOR_OPEN_S - SFX_FLAG);
        this->dyna.actor.world.pos.y = this->posY = (this->posYTick * (5.0f / 3.0f)) + this->dyna.actor.home.pos.y;
        this->timer = 180;
    }

    if (!(player->stateFlags1 & PLAYER_STATE1_TALKING) &&
        CHECK_WEEKEVENTREG(WEEKEVENTREG_GATEKEEPER_OPENED_GORON_SHRINE) && (DECR(this->timer) == 0)) {
        CLEAR_WEEKEVENTREG(WEEKEVENTREG_GATEKEEPER_OPENED_GORON_SHRINE);
    }
}
