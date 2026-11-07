// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_makeoshihiki.h"

s32 ObjMakeoshihiki_GetChildSpawnPointIndex(ObjMakeoshihiki* this, PlayState* play) {
    s32 pad;
    s32 pathIndexOffset1 = Flags_GetSwitch(play, OBJMAKEOSHIHIKI_GET_SWITCH_FLAG_1(&this->actor)) ? 1 : 0;
    s32 pathIndexOffset2 = Flags_GetSwitch(play, OBJMAKEOSHIHIKI_GET_SWITCH_FLAG_2(&this->actor)) ? 2 : 0;

    return pathIndexOffset1 + pathIndexOffset2;
}
