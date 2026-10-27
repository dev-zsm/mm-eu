// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK MapDisp_Init(s32);                         /* extern */
M2C_UNK MapDisp_InitMapData(s32, s32);                    /* extern */

void Scene_CommandMapData(s32 arg0, void *arg1) {
    MapDisp_Init(arg0);
    MapDisp_InitMapData(arg0, M2C_FIELD(arg1, s32 *, 4));
}
