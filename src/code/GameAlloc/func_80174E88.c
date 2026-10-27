// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80086EC0(M2C_UNK *);                   /* extern */

void GameAlloc_Cleanup(M2C_UNK *arg0) {
    M2C_UNK *temp_a0;
    M2C_UNK *var_s0;

    var_s0 = M2C_FIELD(arg0, M2C_UNK **, 0);
    if (arg0 != var_s0) {
        do {
            temp_a0 = var_s0;
            var_s0 = *var_s0;
            func_80086EC0(temp_a0);
        } while (arg0 != var_s0);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x10) = arg0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = arg0;
    M2C_FIELD(arg0, M2C_UNK **, 4) = arg0;
}
