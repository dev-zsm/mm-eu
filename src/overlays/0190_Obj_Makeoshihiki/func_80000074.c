// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_makeoshihiki.h"

void ObjMakeoshihiki_SetSwitchFlags(ObjMakeoshihiki* this, PlayState* play, s32 pathIndex) {
    s32 pad;
    s32 pad2;
    s32 switchFlag1;
    s32 switchFlag2;

    switchFlag2 = OBJMAKEOSHIHIKI_GET_SWITCH_FLAG_2(&this->actor);
    switchFlag1 = OBJMAKEOSHIHIKI_GET_SWITCH_FLAG_1(&this->actor);

    if (pathIndex & 2) {
        Flags_SetSwitch(play, switchFlag2);
    } else {
        Flags_UnsetSwitch(play, switchFlag2);
    }

    if (pathIndex & 1) {
        Flags_SetSwitch(play, switchFlag1);
    } else {
        Flags_UnsetSwitch(play, switchFlag1);
    }
}
