// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapData_MID_GetType(s32);                             /* extern */
s32 MapData_GetMapIId(s32);                             /* extern */

s32 func_80109938(s32 arg0) {
    s32 temp_v0;

    if (MapData_GetMapIId(arg0) != 0x3A) {
        return 1;
    }
    temp_v0 = MapData_MID_GetType(arg0);
    switch (temp_v0) {                              /* irregular */
    case 0:
        return 2;
    case 1:
        return 0;
    default:
        return 0;
    }
}
