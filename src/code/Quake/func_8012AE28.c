// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void *Quake_GetRequest(s16);                           /* extern */

u32 Quake_SetPerturbations(s16 index, s16 y, s16 x, s16 fov, s16 roll) {
    void *temp_v0;

    temp_v0 = Quake_GetRequest(index);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s16 *, 0xC) = y;
        M2C_FIELD(temp_v0, s16 *, 0xE) = x;
        M2C_FIELD(temp_v0, s16 *, 0x10) = fov;
        M2C_FIELD(temp_v0, s16 *, 0x12) = roll;
        return 1;
    }
    return 0;
}
