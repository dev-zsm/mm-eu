// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void func_800B89A4(void *arg0, void *arg1, M2C_UNK arg2) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x120);
    if (M2C_FIELD(temp_v0, s16 *, 0) == 0) {
        M2C_FIELD(temp_v0, void **, 0x34C) = arg1;
        M2C_FIELD(temp_v0, void **, 0x388) = arg1;
    }
    M2C_FIELD(temp_v0, void **, 0x124) = arg1;
    M2C_FIELD(arg1, void **, 0x120) = temp_v0;
    M2C_FIELD(arg0, void **, 0x120) = NULL;
}
