// FLAGS: -O2 -g3 -mips2
#include "types.h"

s8 *Entrance_GetTableEntry(u16);

s32 Entrance_GetSceneIdAbsolute(u16 entrance) {
    s8 temp_v1;
    s32 var_a0;

    temp_v1 = *Entrance_GetTableEntry(entrance);
    if (temp_v1 < 0) {
        var_a0 = -temp_v1;
    } else {
        var_a0 = temp_v1;
    }
    return var_a0;
}
