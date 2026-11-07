// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

s32 ObjOshihiki_NoSwitchPress(ObjOshihiki* this, DynaPolyActor* dyna, PlayState* play) {
    s16 switchFlag;

    if (dyna == NULL) {
        return true;
    }

    if (dyna->actor.id == ACTOR_OBJ_SWITCH) {
        switchFlag = OBJSWITCH_GET_7F00(&dyna->actor);

        switch (OBJSWITCH_GET_33(&dyna->actor)) {
            case OBJSWITCH_NORMAL_BLUE:
                if ((switchFlag == OBJOSHIHIKI_GET_SWITCH_FLAG(&this->dyna.actor)) &&
                    Flags_GetSwitch(play, switchFlag)) {
                    return false;
                }
                break;

            case OBJSWITCH_INVERSE_BLUE:
                if ((switchFlag == OBJOSHIHIKI_GET_SWITCH_FLAG(&this->dyna.actor)) &&
                    !Flags_GetSwitch(play, switchFlag)) {
                    return false;
                }
                break;
        }
    }
    return true;
}
