// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_FloorSwitchUp(ObjSwitch* this, PlayState* play) {
    s32 pad;

    if (OBJ_SWITCH_GET_TYPE(&this->dyna.actor) == OBJSWITCH_TYPE_FLOOR_RUSTY) {
        if (this->colliderTris.base.acFlags & AC_HIT) {
            this->colliderTris.base.acFlags &= ~AC_HIT;
            ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_FloorSwitchPushDownInit, true);
        } else {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderTris.base);
        }
    } else {
        switch (OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor)) {
            case OBJSWITCH_SUBTYPE_ONCE:
                if (DynaPolyActor_IsSwitchPressed(&this->dyna)) {
                    ObjSwitch_SetFloorSwitchSnapPlayerState(this, 1);
                    ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_FloorSwitchPushDownInit, true);
                }
                break;

            case OBJSWITCH_SUBTYPE_SYNC:
                if (DynaPolyActor_IsSwitchPressed(&this->dyna)) {
                    ObjSwitch_SetFloorSwitchSnapPlayerState(this, 1);
                    ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_FloorSwitchPushDownInit, true);
                } else if (Flags_GetSwitch(play, OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
                    ObjSwitch_FloorSwitchPushDownInit(this);
                }
                break;

            case OBJSWITCH_SUBTYPE_TOGGLE:
                if (DynaPolyActor_IsSwitchPressed(&this->dyna)) {
                    s32 isSwitchFlagNotSet =
                        Flags_GetSwitch(play, OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor)) ? false : true;

                    ObjSwitch_SetFloorSwitchSnapPlayerState(this, 1);
                    ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_FloorSwitchPushDownInit, isSwitchFlagNotSet);
                }
                break;

            case OBJSWITCH_SUBTYPE_RESET:
                if (DynaPolyActor_IsSwitchPressed(&this->dyna)) {
                    ObjSwitch_SetFloorSwitchSnapPlayerState(this, 1);
                    ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_FloorSwitchPushDownInit, true);
                }
                break;

            case OBJSWITCH_SUBTYPE_RESET_INVERTED:
                if (DynaPolyActor_IsSwitchPressed(&this->dyna)) {
                    ObjSwitch_SetFloorSwitchSnapPlayerState(this, 2);
                    ObjSwitch_SetSwitchFlagState(this, play, false);
                    ObjSwitch_FloorSwitchPushDownInit(this);
                }
                break;
        }
    }
}
