// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (ObjWturn_Idle), score 2.00 (2 differ, size +1)
#include "generated/mm/z_obj_wturn.h"

void func_80000038(ObjWturn* this, PlayState* play) {
    if ((play->msgCtx.ocarinaMode >= OCARINA_MODE_WARP_TO_GREAT_BAY_COAST) &&
        (play->msgCtx.ocarinaMode <= OCARINA_MODE_WARP_TO_ENTRANCE)) {
        Flags_UnsetSwitch(play, OBJWTURN_GET_SWITCH_FLAG(&this->actor));
        Actor_Kill(&this->actor);
        return;
    }

    if ((Flags_GetSwitch(play, OBJWTURN_GET_SWITCH_FLAG(&this->actor)) && (play->sceneId == SCENE_F40)) ||
        (!Flags_GetSwitch(play, OBJWTURN_GET_SWITCH_FLAG(&this->actor)) && (play->sceneId == SCENE_F41))) {
        ObjWturn_TriggerInversion(this);
    }
}
