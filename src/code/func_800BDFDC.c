// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Actor_SetDropFlag(void *arg0, void *arg1) {
    s32 *temp_v0;
    s32 temp_v1;

    temp_v0 = M2C_FIELD(arg1, s32 **, 0x24);
    if (temp_v0 == NULL) {
        M2C_FIELD(arg0, s8 *, 0x11E) = 0;
        return;
    }
    temp_v1 = *temp_v0;
    if (temp_v1 & 0x800) {
        M2C_FIELD(arg0, s8 *, 0x11E) = 1;
        return;
    }
    if (temp_v1 & 0x1000) {
        M2C_FIELD(arg0, s8 *, 0x11E) = 2;
        return;
    }
    if (temp_v1 & 0x2000) {
        M2C_FIELD(arg0, s8 *, 0x11E) = 0x20;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x11E) = 0;
}
