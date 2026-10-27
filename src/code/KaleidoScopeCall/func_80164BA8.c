// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F4CEC();                            /* extern */

void KaleidoScopeCall_Destroy(void) {
    func_800F4CEC();
}
