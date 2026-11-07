// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void ref_func_808A1884(DoorShutter* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s8 room = this->slidingDoor.dyna.actor.room;
    Vec3f sp44;

    if (this->slidingDoor.dyna.actor.room >= 0) {
        Actor_WorldToActorCoords(&this->slidingDoor.dyna.actor, &sp44, &player->actor.world.pos);

        this->slidingDoor.dyna.actor.room =
            play->transitionActors.list[DOOR_GET_TRANSITION_ID(&this->slidingDoor.dyna.actor)]
                .sides[(sp44.z < 0.0f) ? 0 : 1]
                .room;

        if (room != this->slidingDoor.dyna.actor.room) {
            Room temp = play->roomCtx.curRoom;

            play->roomCtx.curRoom = play->roomCtx.prevRoom;
            play->roomCtx.prevRoom = temp;
            play->roomCtx.activeBufPage ^= 1;
        }
        Room_FinishRoomChange(play, &play->roomCtx);
    }

    this->slidingDoor.unk_15C = 0;
    this->slidingDoor.dyna.actor.velocity.y = 0.0f;

    if (DoorShutter_SetupDoor(this, play) && !(player->stateFlags1 & PLAYER_STATE1_CARRYING_ACTOR)) {
        DoorShutter_SetupAction(this, ref_func_808A1C50);
        if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_DOOR) {
            ref_func_801226E0(play, ((void)0, gSaveContext.respawn[RESPAWN_MODE_DOWN].data));
            player->csId = CS_ID_NONE;
            Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_115);
        }
    }
}
