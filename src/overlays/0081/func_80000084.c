// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

s32 DoorShutter_SetupDoor(DoorShutter* this, PlayState* play) {
    ShutterObjectInfo* sp24 = &ref_D_808A2180[this->unk_163];
    s32 doorType = this->doorType;

    if (doorType != DOORSHUTTER_TYPE_4) {
        if (ref_func_808A0900(this, play)) {
            if ((doorType == DOORSHUTTER_TYPE_7) || (doorType == DOORSHUTTER_TYPE_6)) {
                doorType = DOORSHUTTER_TYPE_1;
            } else if (doorType == DOORSHUTTER_TYPE_BOSS_DOOR) {
                doorType = DOORSHUTTER_TYPE_3;
            } else {
                doorType = DOORSHUTTER_TYPE_0;
            }
        }
    }

    if (doorType == DOORSHUTTER_TYPE_0) {
        this->unk_164 = sp24->index1;
    } else {
        this->unk_164 = sp24->index2;
    }

    if (doorType == DOORSHUTTER_TYPE_1) {
        if (!Flags_GetClear(play, this->slidingDoor.dyna.actor.room)) {
            DoorShutter_SetupAction(this, ref_func_808A0F88);
            this->unk_168 = 1.0f;
            return true;
        }
    } else if ((doorType == DOORSHUTTER_TYPE_2) || (doorType == DOORSHUTTER_TYPE_7)) {
        if (!Flags_GetSwitch(play, DOORSHUTTER_GET_SWITCH_FLAG(&this->slidingDoor.dyna.actor))) {
            DoorShutter_SetupAction(this, ref_func_808A1548);
            this->unk_168 = 1.0f;
            return true;
        }
        DoorShutter_SetupAction(this, ref_func_808A1618);
        return false;
    } else if (doorType == DOORSHUTTER_TYPE_3) {
        DoorShutter_SetupAction(this, ref_func_808A1080);
        this->unk_168 = 1.0f;
        return false;
    }
    DoorShutter_SetupAction(this, ref_func_808A1090);
    return false;
}
