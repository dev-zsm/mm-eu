// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightswitch_Init(Actor* thisx, PlayState* play) {
    ObjLightswitch* this = (ObjLightswitch*)thisx;
    s32 pad;
    u32 isSwitchActivated;
    s32 isTriggered;

    isSwitchActivated = Flags_GetSwitch(play, LIGHTSWITCH_GET_SWITCH_FLAG(&this->actor));
    isTriggered = false;
    Actor_ProcessInitChain(&this->actor, sInitChain);
    Actor_SetFocus(&this->actor, 0.0f);

    if (isSwitchActivated) {
        if (LIGHTSWITCH_GET_TYPE(&this->actor) == LIGHTSWITCH_TYPE_FAKE) {
            isTriggered = true;
        } else {
            ObjLightSwitch_SetupEnabled(this);
        }
    } else {
        ObjLightswitch_SetupIdle(this);
    }

    ObjLightswitch_InitCollider(this, play);

    if (LIGHTSWITCH_GET_INVISIBLE(&this->actor)) {
        
        this->actor.draw = NULL;
    }

    if (isTriggered) {
        Actor_Kill(&this->actor);
    }
}
