// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_spiral.h"

void ref_func_809A2FF8(DoorSpiral* this, PlayState* play) {
    Player* player;
    u32 transitionId;

    if (this->shouldClimb) {
        DoorSpiral_SetupAction(this, ref_func_809A3098);
    } else if (ref_func_809A2EA0(this, play) != 0) {
        player = GET_PLAYER(play);
        player->doorType = PLAYER_DOORTYPE_STAIRCASE;
        player->doorDirection = this->direction;
        player->doorActor = &this->actor;
        transitionId = DOOR_GET_TRANSITION_ID(&this->actor);
        player->doorNext = (play->transitionActors.list[transitionId].params >> 0xA);
        ref_func_80122F28(player);
    }
}
