// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void *Quake_GetRequest(s16);                           /* extern */

u32 Quake_SetSpeed(s16 index, s16 speed) {
    void *temp_v0;

    temp_v0 = Quake_GetRequest(index);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s16 *, 0x1A) = speed;
        return 1;
    }
    return 0;
}
