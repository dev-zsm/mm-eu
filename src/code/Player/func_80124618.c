// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Player_MeleeWeaponFromIA(s32 arg0) {
    s32 temp_v0;

    temp_v0 = arg0 - 2;
    if ((temp_v0 > 0) && (temp_v0 < 7)) {
        return temp_v0;
    }
    return 0;
}
