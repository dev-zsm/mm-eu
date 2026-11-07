// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_FloorSwitchDown(ObjSwitch* this, PlayState* play) {
    s32 pad;
    u32 subType = OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor);

    switch (subType) {
        case OBJSWITCH_SUBTYPE_ONCE:
        case OBJSWITCH_SUBTYPE_SYNC:
            if (!Flags_GetSwitch(play, OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
                if ((play->sceneId == SCENE_SECOM) && DynaPolyActor_IsSwitchPressed(&this->dyna)) {
                    ObjSwitch_SetSwitchFlagState(this, play, true);
                } else {
                    ObjSwitch_FloorSwitchRiseUpInit(this);
                }
            }
            break;

        case OBJSWITCH_SUBTYPE_TOGGLE:
        case OBJSWITCH_SUBTYPE_RESET:
        case OBJSWITCH_SUBTYPE_RESET_INVERTED:
            if (!DynaPolyActor_IsSwitchPressed(&this->dyna) &&
                (!Player_InCsMode(play) || (play->sceneId == SCENE_SECOM))) {
                if (this->floorSwitchReleaseTimer <= 0) {
                    if (subType == OBJSWITCH_SUBTYPE_RESET) {
                        ObjSwitch_SetSwitchFlagState(this, play, false);
                        ObjSwitch_FloorSwitchRiseUpInit(this);
                    } else if (subType == OBJSWITCH_SUBTYPE_RESET_INVERTED) {
                        ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_FloorSwitchRiseUpInit, true);
                    } else {
                        ObjSwitch_FloorSwitchRiseUpInit(this);
                    }
                }
            } else {
                if (play->sceneId == SCENE_SECOM) {
                    this->floorSwitchReleaseTimer = 2;
                } else {
                    this->floorSwitchReleaseTimer = 6;
                }
            }
            break;
    }
}
