// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_CrystalSwitchOff(ObjSwitch* this, PlayState* play) {
    s32 switchHit = (this->colliderJntSph.base.acFlags & AC_HIT) != 0;
    s32 canActivate = switchHit && !(this->collisionFlags & AC_HIT) && (this->disableCrystalSwitchTimer <= 0);

    if (switchHit) {
        this->disableCrystalSwitchTimer = 10;
    }
    switch (OBJ_SWITCH_GET_SUBTYPE(&this->dyna.actor)) {
        case OBJSWITCH_SUBTYPE_ONCE:
            if (canActivate) {
                ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_CrystalSwitchTurnOnInit, true);
            }
            break;

        case OBJSWITCH_SUBTYPE_SYNC:
            if (canActivate) {
                ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_CrystalSwitchTurnOnInit, true);

            } else if (Flags_GetSwitch(play, OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
                this->disableCrystalSwitchTimer = 10;
                ObjSwitch_CrystalSwitchTurnOnInit(this);
            }
            break;

        case OBJSWITCH_SUBTYPE_TOGGLE:
            if (canActivate) {
                ObjSwitch_TryPlayCutsceneInit(this, play, ObjSwitch_CrystalSwitchTurnOnInit, true);
            }
            ObjSwitch_CrystalUpdateTimer(this);
            break;
    }
}
