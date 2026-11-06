// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void DoorShutter_Update(Actor* thisx, PlayState* play) {
    DoorShutter* this = (DoorShutter*)thisx;
    Player* player = GET_PLAYER(play);

    if (!(player->stateFlags1 &
          (PLAYER_STATE1_TALKING | PLAYER_STATE1_DEAD | PLAYER_STATE1_400 | PLAYER_STATE1_10000000)) ||
        (this->actionFunc == DoorShutter_SetupType)) {
        this->actionFunc(this, play);

        if (this->unk_163 == 7) {
            this->slidingDoor.dyna.actor.home.rot.z =
                Math_Vec3f_DistXZ(&this->slidingDoor.dyna.actor.home.pos, &this->slidingDoor.dyna.actor.world.pos) *
                -100.0f;
        }
    }
}
