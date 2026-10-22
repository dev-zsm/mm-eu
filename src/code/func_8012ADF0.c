// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *Quake_GetRequest(s16);                           /* extern */

s16 Quake_GetTimeLeft(s16 arg0) {
    void *temp_v0;

    temp_v0 = Quake_GetRequest(arg0);
    if (temp_v0 != NULL) {
        return M2C_FIELD(temp_v0, s16 *, 0x1E);
    }
    return 0;
}
