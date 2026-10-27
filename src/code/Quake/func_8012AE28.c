// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *Quake_GetRequest(s16);                           /* extern */

s32 Quake_SetPerturbations(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    void *temp_v0;

    temp_v0 = Quake_GetRequest(arg0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s16 *, 0xC) = arg1;
        M2C_FIELD(temp_v0, s16 *, 0xE) = arg2;
        M2C_FIELD(temp_v0, s16 *, 0x10) = arg3;
        M2C_FIELD(temp_v0, s16 *, 0x12) = arg4;
        return 1;
    }
    return 0;
}
