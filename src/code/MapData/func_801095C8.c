// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK MapData_GetMapTexOffsetGameplayDangeonKeep(s32, s32 *, s32 *);           /* extern */
M2C_UNK MapData_GetMapTexGameplayDangeonKeepOffset(s32, s32 *, s32 *);           /* extern */
s32 MapData_MID_GetType();                                /* extern */

void MapData_GetMapTexOffset(s32 mapId, s32 *offsetX, s32 *offsetY) {
    s32 temp_v0;

    temp_v0 = MapData_MID_GetType();
    switch (temp_v0) {                              /* irregular */
    case 0:
        MapData_GetMapTexOffsetGameplayDangeonKeep(mapId, offsetX, offsetY);
        return;
    case 1:
        MapData_GetMapTexGameplayDangeonKeepOffset(mapId, offsetX, offsetY);
        return;
    default:
        *offsetY = 0;
        *offsetX = 0;
        return;
    }
}
