// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightSwitch_Enabled(ObjLightswitch* this, PlayState* play) {
    s32 actorType = LIGHTSWITCH_GET_TYPE(&this->actor);

    if (actorType == LIGHTSWITCH_TYPE_REGULAR) {
        
        if (!Flags_GetSwitch(play, LIGHTSWITCH_GET_SWITCH_FLAG(&this->actor))) {
            ObjLightSwitch_SetupDisabled(this);
        }
    } else if (actorType == LIGHTSWITCH_TYPE_FLIP) {
        if (this->hitState >= 10) {
            this->hitState = 0;
            ObjLightswitch_SetAction(this, ObjLightSwitch_SetupDisabled, 0);
        }
    } else if (this->hitState == 0) {
        if (this->colorShiftTimer >= 13) {
            ObjLightswitch_UpdateSwitchFlags(this, play, 0);
            ObjLightSwitch_SetupDisabled(this);
        } else {
            this->colorShiftTimer++;
        }
    } else {
        this->colorShiftTimer = 0;
    }
    this->edgeRot += this->edgeRotSpeed;
}
