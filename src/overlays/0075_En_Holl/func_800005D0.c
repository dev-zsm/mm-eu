// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_holl.h"

void EnHoll_TransparentIdle(EnHoll* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 useViewEye = gDbgCamEnabled || (play->csCtx.state != CS_STATE_IDLE);
    Vec3f transformedPlayerPos;
    f32 enHollTop;
    f32 playerDistFromCentralPlane;

    Actor_WorldToActorCoords(&this->actor, &transformedPlayerPos,
                             useViewEye ? &play->view.eye : &player->actor.world.pos);
    enHollTop = (play->sceneId == SCENE_PIRATE) ? EN_HOLL_TOP_PIRATE : EN_HOLL_TOP_DEFAULT;

    if ((transformedPlayerPos.y > EN_HOLL_BOTTOM_DEFAULT) && (transformedPlayerPos.y < enHollTop) &&
        (fabsf(transformedPlayerPos.x) < EN_HOLL_HALFWIDTH_TRANSPARENT)) {
        if (playerDistFromCentralPlane = fabsf(transformedPlayerPos.z),
            playerDistFromCentralPlane < EN_HOLL_ACTIVATION_PLANE_DISTANCE &&
                playerDistFromCentralPlane > EN_HOLL_LOADING_PLANE_DISTANCE) {
            s32 enHollId = EN_HOLL_GET_ID(&this->actor);
            s32 playerSide = (transformedPlayerPos.z < 0.0f) ? EN_HOLL_BEHIND : EN_HOLL_BEFORE;
            TransitionActorEntry* transitionActorEntry = &play->transitionActors.list[enHollId];
            s8 room = transitionActorEntry->sides[playerSide].room;

            this->actor.room = room;

            if ((this->actor.room != play->roomCtx.curRoom.num) &&
                Room_RequestNewRoom(play, &play->roomCtx, this->actor.room)) {
                this->actionFunc = EnHoll_RoomTransitionIdle;
            }
        }
    }
}
