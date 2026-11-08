// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK MapData_GetMapTexDimGameplayDangeonKeep(s32, s32 *, s32 *);           /* extern */
M2C_UNK MapData_GetMapTexGameplayDangeonKeepDim(s32, s32 *, s32 *);           /* extern */
s32 MapData_MID_GetType();                                /* extern */

void MapData_GetMapTexDim(s32 mapId, s32 *width, s32 *height) {
    s32 temp_v0;

    temp_v0 = MapData_MID_GetType();
    switch (temp_v0) {                              /* irregular */
    case 0:
        MapData_GetMapTexDimGameplayDangeonKeep(mapId, width, height);
        return;
    case 1:
        MapData_GetMapTexGameplayDangeonKeepDim(mapId, width, height);
        return;
    default:
        *height = 0;
        *width = 0;
        return;
    }
}
