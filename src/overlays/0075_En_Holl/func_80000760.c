// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_VerticalBgCoverIdle(EnHoll* this, PlayState* play) {
    f32 playerDistFromCentralPlane;

    if ((this->actor.xzDistToPlayer < EN_HOLL_RADIUS) &&
        (playerDistFromCentralPlane = fabsf(this->actor.playerHeightRel),
         playerDistFromCentralPlane < EN_HOLL_ACTIVATION_PLANE_DISTANCE_VERTICAL)) {
        if (playerDistFromCentralPlane < EN_HOLL_LOADING_PLANE_DISTANCE_VERTICAL) {
            play->bgCoverAlpha = 255;
        } else {
            play->bgCoverAlpha = EN_HOLL_SCALE_BG_COVER_ALPHA(playerDistFromCentralPlane);
        }
        if (playerDistFromCentralPlane > EN_HOLL_LOADING_PLANE_DISTANCE_VERTICAL) {
            s32 enHollId = EN_HOLL_GET_ID(&this->actor);
            s32 playerSide = (this->actor.playerHeightRel > 0.0f) ? EN_HOLL_ABOVE : EN_HOLL_BELOW;

            this->actor.room = play->transitionActors.list[enHollId].sides[playerSide].room;

            if ((this->actor.room != play->roomCtx.curRoom.num) &&
                Room_RequestNewRoom(play, &play->roomCtx, this->actor.room)) {
                this->actionFunc = EnHoll_RoomTransitionIdle;
                this->bgCoverAlphaActive = true;
            }
        }
    } else if (this->bgCoverAlphaActive) {
        this->bgCoverAlphaActive = false;
        play->bgCoverAlpha = 0;
    }
}
