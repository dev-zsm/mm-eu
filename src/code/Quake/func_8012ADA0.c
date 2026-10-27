// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *Quake_GetRequest(s16);                           /* extern */

s32 Quake_SetDuration(s16 arg0, s16 arg1) {
    void *temp_v0;

    temp_v0 = Quake_GetRequest(arg0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s16 *, 0x1E) = arg1;
        M2C_FIELD(temp_v0, s16 *, 2) = (s16) M2C_FIELD(temp_v0, s16 *, 0x1E);
        return 1;
    }
    return 0;
}
