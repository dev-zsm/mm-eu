// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 DynaPoly_GetActor();                                /* extern */
M2C_UNK DynaPolyActor_SetPlayerAbove(s32);                         /* extern */

void DynaPoly_SetPlayerAbove(void) {
    s32 temp_v0;

    temp_v0 = DynaPoly_GetActor();
    if (temp_v0 != 0) {
        DynaPolyActor_SetPlayerAbove(temp_v0);
    }
}
