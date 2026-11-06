// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

void ObjOshihiki_Push(ObjOshihiki* this, PlayState* play) {
    s32 pad;
    Player* player = GET_PLAYER(play);
    f32 pushDistSigned;
    s32 stopFlag;

    this->stateFlags |= PUSHBLOCK_PUSH;
    stopFlag = Math_StepToF(&this->pushDist, 60.0f, this->pushSpeed);

    pushDistSigned = ((this->direction >= 0.0f) ? 1.0f : -1.0f) * this->pushDist;
    this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + (pushDistSigned * this->yawSin);
    this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + (pushDistSigned * this->yawCos);

    if (!ObjOshihiki_CheckFloor(this, play)) {
        this->dyna.actor.home.pos.x = this->dyna.actor.world.pos.x;
        this->dyna.actor.home.pos.z = this->dyna.actor.world.pos.z;
        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
        this->pushDist = 0.0f;
        this->pushSpeed = 0.0f;
        ObjOshihiki_SetupFall(this, play);
    } else if (stopFlag) {
        player = GET_PLAYER(play);

        if (ObjOshihiki_CheckWall(play, this->dyna.yRotation, this->dyna.pushForce, this)) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        }

        this->dyna.actor.home.pos.x = this->dyna.actor.world.pos.x;
        this->dyna.actor.home.pos.z = this->dyna.actor.world.pos.z;
        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
        this->pushDist = 0.0f;
        this->pushSpeed = 0.0f;
        this->timer = 10;

        if (this->floorBgIds[this->highestFloor] == BGCHECK_SCENE) {
            ObjOshihiki_SetupOnScene(this, play);
        } else {
            ObjOshihiki_SetupOnActor(this, play);
        }
    }

    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
}
