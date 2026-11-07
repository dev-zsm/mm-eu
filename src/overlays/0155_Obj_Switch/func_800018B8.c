// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_LargeFloorSwitchDown(ObjSwitch* this, PlayState* play) {
    s32 subType = OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor);

    if (subType == OBJSWITCH_SUBTYPE_ONCE) {
        if (!Flags_GetSwitch(play, OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
            ObjSwitch_LargeFloorSwitchRiseUpInit(this);
        }
    } else if (subType == OBJSWITCH_SUBTYPE_RESET || subType == OBJSWITCH_SUBTYPE_RESET_INVERTED) {
        if (!DynaPolyActor_IsHeavySwitchPressed(&this->dyna) && !Player_InCsMode(play)) {
            if (this->floorSwitchReleaseTimer <= 0) {
                if (OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor) == OBJSWITCH_SUBTYPE_RESET) {
                    ObjSwitch_SetSwitchFlagState(this, play, false);
                    ObjSwitch_LargeFloorSwitchRiseUpInit(this);
                } else {
                    ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_LargeFloorSwitchRiseUpInit, true);
                }
            }
        } else {
            this->floorSwitchReleaseTimer = 6;
        }
    }
}
