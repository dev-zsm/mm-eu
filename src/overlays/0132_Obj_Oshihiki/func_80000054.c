// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

s32 ObjOshihiki_StrongEnough(ObjOshihiki* this, PlayState* play) {
    s32 strength = OBJOSHIHIKI_GET_F(&this->dyna.actor);

    if (this->cantMove) {
        return false;
    }

    if ((strength == OBJOSHIHIKI_F_0) || (strength == OBJOSHIHIKI_F_3)) {
        return true;
    }

    if (Player_GetStrength() >= PLAYER_STRENGTH_ZORA) {
        return true;
    }
    return false;
}
