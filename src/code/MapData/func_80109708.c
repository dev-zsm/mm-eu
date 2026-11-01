// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 MapData_GetMapColorIndexGameplayDangeonKeep(s32);                             /* extern */
s32 MapData_GetMapGrandColorIndex(s32);                             /* extern */
s32 MapData_MID_GetType();                                /* extern */

s32 MapData_GetMapColorIndex(s32 arg0) {
    s32 temp_v0;

    temp_v0 = MapData_MID_GetType();
    switch (temp_v0) {                              /* irregular */
    case 0:
        return MapData_GetMapColorIndexGameplayDangeonKeep(arg0);
    case 1:
        return MapData_GetMapGrandColorIndex(arg0);
    default:
        return 0;
    }
}
