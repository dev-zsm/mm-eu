// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s16 Rand_S16Offset(M2C_UNK, M2C_UNK, void *);        /* extern */

void EnHy_Blink(void *arg0, s32 arg1) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3E8);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x3E8) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x3E8);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x3E6) = (s16) (M2C_FIELD(arg0, s16 *, 0x3E6) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x3E6) >= arg1) {
            M2C_FIELD(arg0, s16 *, 0x3E6) = 0;
            M2C_FIELD(arg0, s16 *, 0x3E8) = Rand_S16Offset(0x1E, 0x1E, arg0);
        }
    }
}
