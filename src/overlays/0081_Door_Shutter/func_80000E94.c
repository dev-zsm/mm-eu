// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void ref_func_808A1784(DoorShutter* this, PlayState* play) {
    if (this->unk_167 != 0) {
        if (ref_func_800F22C4(this->csId, &this->slidingDoor.dyna.actor) != 0) {
            if (this->unk_167 < 0) {
                if ((play->state.frames % 2) != 0) {
                    this->unk_167++;
                }
            } else {
                this->unk_167--;
            }
        }
    } else if (ref_func_808A1478(this, play, 0.0f)) {
        u8 doorType = this->doorType;

        if ((doorType != DOORSHUTTER_TYPE_0) && (doorType != DOORSHUTTER_TYPE_1) &&
            (((doorType != DOORSHUTTER_TYPE_7) && (doorType != DOORSHUTTER_TYPE_6)) || !ref_func_808A0900(this, play))) {
            DoorShutter_SetupAction(this, ref_func_808A1618);
        } else {
            DoorShutter_SetupAction(this, ref_func_808A1090);
        }
        Audio_RestorePrevBgm();
    }
}
