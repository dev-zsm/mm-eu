// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_purify.h"

s32 ObjPurify_IsPurified(ObjPurify* this) {
    ObjPurifyInfo* info = &sObjPurifyInfo[OBJPURIFY_GET_INFO_INDEX(&this->dyna.actor)];

    if (!info->isDekuCity) {
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_12_01)) {
            return true;
        }
    } else {
        if (CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_WOODFALL_TEMPLE)) {
            return true;
        }
    }
    return false;
}
