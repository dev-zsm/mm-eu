// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_SetSwitchFlagState(ObjSwitch* this, PlayState* play, s32 setFlag) {
    if (setFlag) {
        s32 switchFlag = OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor);

        Flags_SetSwitch(play, switchFlag);
    } else {
        s32 switchFlag = OBJ_SWITCH_GET_SWITCH_FLAG(&this->dyna.actor);

        Flags_UnsetSwitch(play, switchFlag);
    }
}
