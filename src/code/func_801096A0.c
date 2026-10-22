// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80109328(s32, s32 *);                  /* extern */
M2C_UNK func_8010940C(s32, s32 *);                  /* extern */
s32 MapData_MID_GetType();                                /* extern */

void MapData_GetDrawType(s32 arg0, s32 *arg1) {
    s32 temp_v0;

    temp_v0 = MapData_MID_GetType();
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_80109328(arg0, arg1);
        return;
    case 1:
        func_8010940C(arg0, arg1);
        return;
    default:
        *arg1 = 0;
        return;
    }
}
