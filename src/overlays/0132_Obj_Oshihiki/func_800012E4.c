// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

void ObjOshihiki_Fall(ObjOshihiki* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s16 temp_t4;

    this->stateFlags |= PUSHBLOCK_FALL;

    if (fabsf(this->dyna.pushForce) > 0.001f) {
        this->dyna.pushForce = 0.0f;
        player->stateFlags2 &= ~PLAYER_STATE2_10;
    }

    Actor_MoveWithGravity(&this->dyna.actor);

    if (ObjOshihiki_CheckGround(this, play)) {
        if (this->floorBgIds[this->highestFloor] == BGCHECK_SCENE) {
            ObjOshihiki_SetupOnScene(this, play);
        } else {
            ObjOshihiki_SetupOnActor(this, play);
        }
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        Actor_PlaySfx(&this->dyna.actor, NA_SE_PL_WALK_GROUND + SurfaceType_GetSfxOffset(
                                                                    &play->colCtx, this->floorPolys[this->highestFloor],
                                                                    this->floorBgIds[this->highestFloor]));
    }
}
