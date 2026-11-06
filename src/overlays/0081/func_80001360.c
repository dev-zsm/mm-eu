// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void ref_func_808A1C50(DoorShutter* this, PlayState* play) {
    if (this->unk_167++ > 30) {
        if (GET_PLAYER(play)->csAction == PLAYER_CSACTION_115) {
            Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_END);
        }
        DoorShutter_SetupDoor(this, play);
    }
}
