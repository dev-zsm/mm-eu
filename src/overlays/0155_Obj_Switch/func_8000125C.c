// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_EyeSwitchClosed(ObjSwitch* this, PlayState* play) {
    switch (OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor)) {
        case OBJSWITCH_SUBTYPE_ONCE:
            if (!Flags_GetSwitch(play, OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
                OBJ_SWITCH_UNSET_FROZEN(&this->dyna.actor);
                ObjSwitch_EyeSwitchOpeningInit(this);
            }
            break;

        case OBJSWITCH_SUBTYPE_TOGGLE:
            if (ObjSwitch_IsEyeSwitchHit(this) || OBJ_SWITCH_IS_FROZEN(&this->dyna.actor)) {
                OBJ_SWITCH_UNSET_FROZEN(&this->dyna.actor);
                ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_EyeSwitchOpeningInit, false);
            }
            break;
    }
}
