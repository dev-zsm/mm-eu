// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void ref_func_808A1288(DoorShutter* this, PlayState* play) {
    if (this->slidingDoor.dyna.actor.category == ACTORCAT_DOOR) {
        Player* player = GET_PLAYER(play);
        s32 sp38 = this->unk_164;
        s32 sp34 = 0xF;

        if (DoorShutter_SetupDoor(this, play)) {
            sp34 = 0x20;
        }

        DoorShutter_SetupAction(this, ref_func_808A1684);

        this->unk_164 = sp38;
        this->unk_168 = 0.0f;

        Camera_ChangeDoorCam(play->cameraPtrs[CAM_ID_MAIN], &this->slidingDoor.dyna.actor, player->cv.doorBgCamIndex,
                             this->unk_168, 12, sp34, 10);
    }
}
