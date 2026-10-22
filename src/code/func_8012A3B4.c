// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80080600(M2C_UNK, void *);             /* extern */
M2C_UNK PreNMI_Stop(void *);                      /* extern */

void PreNMI_Update(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0xA4);
    if (temp_v0 == 0) {
        func_80080600(1, arg0);
        PreNMI_Stop(arg0);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xA4) = (s32) (temp_v0 - 1);
}
