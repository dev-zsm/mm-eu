// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_open_shutter.h"

void ref_func_80ACAD88(BgOpenShutter* this, PlayState* play) {
    s32 doorDirection;

    if (this->slidingDoor.unk_15C != 0) {
        Player* player = GET_PLAYER(play);

        Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_SLIDE_DOOR_OPEN);
        Camera_ChangeDoorCam(play->cameraPtrs[CAM_ID_MAIN], &this->slidingDoor.dyna.actor, player->cv.doorBgCamIndex,
                             0.0f, 12, 15, 10);
        this->unk_164 = 0;
        this->actionFunc = ref_func_80ACAE5C;
        this->slidingDoor.dyna.actor.velocity.y = 0.0f;
    } else {
        Player* player = GET_PLAYER(play);

        doorDirection = ref_func_80ACABA8(this, play);
        if (doorDirection > 0) {
            player->doorType = PLAYER_DOORTYPE_SLIDING;
            player->doorDirection = doorDirection;
            player->doorActor = &this->slidingDoor.dyna.actor;
            ref_func_80122F28(player);
        }
    }
}
