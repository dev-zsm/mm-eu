// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void ref_func_808A1618(DoorShutter* this, PlayState* play) {
    if ((this->slidingDoor.unk_15C == 0) &&
        !Flags_GetSwitch(play, DOORSHUTTER_GET_SWITCH_FLAG(&this->slidingDoor.dyna.actor))) {
        DoorShutter_SetupAction(this, ref_func_808A1548);
    } else {
        ref_func_808A1090(this, play);
    }
}
