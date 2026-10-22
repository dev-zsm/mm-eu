// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Quake_Remove(s32);                         /* extern */
s32 Quake_GetRequest(s16);                             /* extern */

s32 Quake_RemoveRequest(s16 arg0) {
    s32 temp_v0;

    temp_v0 = Quake_GetRequest(arg0);
    if (temp_v0 != 0) {
        Quake_Remove(temp_v0);
        return 1;
    }
    return 0;
}
