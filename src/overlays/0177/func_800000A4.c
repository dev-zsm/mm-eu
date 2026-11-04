// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightswitch_UpdateSwitchFlags(ObjLightswitch* this, PlayState* play, s32 set) {
    Actor* thisx = &this->actor;

    if (set) {
        Flags_SetSwitch(play, LIGHTSWITCH_GET_SWITCH_FLAG(thisx));
    } else {
        Flags_UnsetSwitch(play, LIGHTSWITCH_GET_SWITCH_FLAG(thisx));
    }
}
